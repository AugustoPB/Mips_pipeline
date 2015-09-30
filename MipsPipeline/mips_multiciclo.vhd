-------------------------------------------------------------------------
--
-- I M P L E M E N T A   O   P A R C I A L  D O  M I P S   (nov/2010)
--
--  ImPoRtAnTe :   VERSO  SEM MULTIPLICAO/DIVISO
--
--  Professores     Fernando Moraes / Ney Calazans
--
--  ==> The top-level processor entity is MRstd
--  21/06/2010 - Bug corrigido no mux que gera op1 - agora recebe npc e
--		no pc.
--  17/11/2010 (Ney) - Bugs corrigidos:
--	1 - Decodificao das instrues BGEZ e BLEZ estava incompleta
--		Modificadas linhas 395 e 396 abaixo
--	2 - Definio de que linhas escolhem o registrador a ser escrito
--	nas instrues de deslocamento (SSLL, SLLV, SSRA, SRAV, SSRL e SRLV)
--		Acrescentadas linhas 325 a 327 abaixo
-------------------------------------------------------------------------

--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-- package with basic types
--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
library IEEE;
use IEEE.Std_Logic_1164.all;

package p_MRstd is  
    
    -- inst_type defines the instructions decodeable by the control unit
    type inst_type is  
            ( ADDU, SUBU, AAND, OOR, XXOR, NNOR, SSLL, SLLV, SSRA, SRAV, SSRL, SRLV,
            ADDIU, ANDI, ORI, XORI, LUI, LBU, LW, SB, SW, SLT, SLTU, SLTI,
            SLTIU, BEQ, BGEZ, BLEZ, BNE, J, JAL, JALR, JR, NOP, invalid_instruction);
 
    type microinstruction is record
            CY1:   std_logic;       -- command of the first stage
            CY2:   std_logic;       --    "    of the second stage
            walu:  std_logic;       --    "    of the third stage
            wmdr:  std_logic;       --    "    of the fourth stage
            wpc:   std_logic;       -- PC write enable
            wreg:  std_logic;       -- register bank write enable
            ce:    std_logic;       -- Chip enable and R_W controls
            rw:    std_logic;
            bw:    std_logic;       -- Byte-word control (mem write only)
            i:     inst_type;       -- operation specification
    end record;
         
end p_MRstd;


--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-- Generic multibit register  
--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
library IEEE;
use IEEE.std_logic_1164.all;

entity regnbit is
           generic(REG_SIZE : integer := 31; INIT_VALUE : STD_LOGIC_VECTOR(31 downto 0) := (others=>'0');  SENSIBILITY : std_logic := '1');
           port(  ck, rst, ce : in std_logic;
                  D : in  STD_LOGIC_VECTOR (REG_SIZE downto 0);
                  Q : out STD_LOGIC_VECTOR (REG_SIZE downto 0)
               );
end regnbit;

architecture regnbit of regnbit is 
begin

  process(ck, rst)
  begin
       if rst = '1' then
              Q <= INIT_VALUE(REG_SIZE downto 0);
       elsif ck'event and ck = SENSIBILITY then
           if ce = '1' then
              Q <= D; 
           end if;
       end if;
  end process;
        
end regnbit;

--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-- Generic bit register  
--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
library IEEE;
use IEEE.std_logic_1164.all;

entity regbit is
           generic(SENSIBILITY : STD_LOGIC := '1'; INIT_VALUE : STD_LOGIC := '0');
           port(  ck, rst, ce : in std_logic;
                  D : in  STD_LOGIC;
                  Q : out STD_LOGIC );
end regbit;

architecture regbit of regbit is 
begin

  process(ck, rst)
  begin
       if rst = '1' then
              Q <= INIT_VALUE;
       elsif ck'event and ck = SENSIBILITY then
           if ce = '1' then
              Q <= D; 
           end if;
       end if;
  end process;
        
end regbit;

--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-- Generic microInstruction register  
--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
library IEEE;
use IEEE.std_logic_1164.all;
use work.p_MRstd.all;

entity regmins is
           generic(SENSIBILITY : STD_LOGIC := '1'; INIT_VALUE : inst_type := invalid_instruction);
           port(  ck, rst, ce : in std_logic;
                  D : in  microinstruction;
                  Q : out microinstruction );
end regmins;

architecture regmins of regmins is 
begin

  process(ck, rst)
  begin
       if rst = '1' then
              Q.i <= INIT_VALUE;
				  Q.CY1 <= '0';
				  Q.CY2 <= '0';
				  Q.walu <= '0';
				  Q.wmdr <= '0';
				  Q.wpc <= '0';
				  Q.wreg <= '0';
				  Q.ce <= '0';
				  Q.rw <= '0';
				  Q.bw <= '1';
       elsif ck'event and ck = SENSIBILITY then
           if ce = '1' then
              Q <= D; 
           end if;
       end if;
  end process;
        
end regmins;

--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-- Pulse Signal
--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
library IEEE;
use IEEE.std_logic_1164.all;
use work.p_MRstd.all;

entity pulsesig is
           port(  ck, rst : in std_logic;
                  D : in  microinstruction;
                  Q : out STD_LOGIC_VECTOR (2 downto 0));
end pulsesig;

architecture pulsesig of pulsesig is 
	type type_state is (Sstore, Sload, Send);
   signal PST, NST : type_state;
begin

  process(rst, ck)
    begin
       if rst='0' then
            PST <= Sstore;
       elsif ck'event then
                 
			   PST <= NST;
                
       end if;
   end process;
 
    process(PST, D.i)
    begin
       case PST is

            when Sstore =>	if D.i = SB or D.i = SW then
										NST <= Send;
									elsif D.i = LBU or D.i = LW then
										NST <= Sload;
									else
										NST <= Sstore;
									end if;
									
				when Sload => NST <= Sstore;
            when Send =>  NST <= Sstore; 	
       end case;
    end process;
	 
	 Q(2) <= '1' when (PST = Sstore and (D.i = SW or D.i = SB or D.i = LBU or D.i = LW)) or PST = Sload else '0'; 
    Q(1) <= D.rw;
	 Q(0) <= D.bw;
        
end pulsesig;

--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-- Register Bank (R0..R31) - 31 GENERAL PURPOSE 16-bit REGISTERS
--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
library IEEE;
use IEEE.Std_Logic_1164.all;
use ieee.STD_LOGIC_UNSIGNED.all;   
use work.p_MRstd.all;

entity reg_bank is
       port( ck, rst, wreg :    in std_logic;
             AdRs, AdRt, adRd : in std_logic_vector( 4 downto 0);
             RD : in std_logic_vector(31 downto 0);
             R1, R2: out std_logic_vector(31 downto 0) 
           );
end reg_bank;

architecture reg_bank of reg_bank is
   type bank is array(0 to 31) of std_logic_vector(31 downto 0);
   signal reg : bank ;                            
   signal wen : std_logic_vector(31 downto 0) ;
begin            

    g1: for i in 0 to 31 generate        

        -- Remember register $0 is the constant 0, not a register.
        -- This is implemented by never enabling writes to register $0
        wen(i) <= '1' when i/=0 and adRD=i and wreg='1' else '0';
         
        -- Remember register $29, the stack pointer, points to some place
        -- near the bottom of the data memory, not the usual place 
		-- assigned by the MIPS simulator!!
        g2: if i=29 generate -- SP ---  x10010000 + x800 -- top of stack
           r29: entity work.regnbit generic map( SENSIBILITY => '0', INIT_VALUE=>x"10010800")    
                                  port map(ck=>ck, rst=>rst, ce=>wen(i), D=>RD, Q=>reg(i));
        end generate;  
                
        g3: if i/=29 generate 
           rx: entity work.regnbit generic map(SENSIBILITY => '0') port map(ck=>ck, rst=>rst, ce=>wen(i), D=>RD, Q=>reg(i));                    
        end generate;
                   
   end generate g1;   
    

    R1 <= reg(CONV_INTEGER(AdRs));    -- source1 selection 

    R2 <= reg(CONV_INTEGER(AdRt));    -- source2 selection 
   
end reg_bank;



--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-- ALU - operation depends only on the current instruction 
--       (decoded in the control unit)
--
-- 22/11/2004 - subtle error correctionwas done for J!
-- Part of the work for J has been done before, by shifting IR(15 downto 0)
-- left by two bits before writing data to the IMED register 
--
--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_unsigned.all;
use IEEE.std_logic_arith.all;
use work.p_MRstd.all;

entity alu is
       port( op1, op2 : in std_logic_vector(31 downto 0);
             outalu :   out std_logic_vector(31 downto 0);   
             op_alu : in inst_type   
           );
end alu;

architecture alu of alu is 
   signal menorU, menorS : std_logic ;
begin
  
    menorU <=  '1' when op1 < op2 else '0';
    menorS <=  '1' when ieee.Std_Logic_signed."<"(op1,  op2) else '0' ; -- signed
    
    outalu <=  
        op1 - op2                                when  op_alu=SUBU                     else
        op1 and op2                              when  op_alu=AAND  or op_alu=ANDI     else 
        op1 or  op2                              when  op_alu=OOR   or op_alu=ORI      else 
        op1 xor op2                              when  op_alu=XXOR  or op_alu=XORI     else 
        op1 nor op2                              when  op_alu=NNOR                     else 
        op2(15 downto 0) & x"0000"               when  op_alu=LUI                      else
        (0=>menorU, others=>'0')                 when  op_alu=SLTU  or op_alu=SLTIU    else   -- signed
        (0=>menorS, others=>'0')                 when  op_alu=SLT   or op_alu=SLTI     else   -- unsigned
        op1(31 downto 28) & op2(27 downto 0)     when  op_alu=J     or op_alu=JAL      else 
        op1                                      when  op_alu=JR    or op_alu=JALR     else 
        to_StdLogicVector(to_bitvector(op1) sll  CONV_INTEGER(op2(10 downto 6)))   when  op_alu=SSLL   else 
        to_StdLogicVector(to_bitvector(op2) sll  CONV_INTEGER(op1(5 downto 0)))    when  op_alu=SLLV   else 
        to_StdLogicVector(to_bitvector(op1) sra  CONV_INTEGER(op2(10 downto 6)))   when  op_alu=SSRA   else 
        to_StdLogicVector(to_bitvector(op2) sra  CONV_INTEGER(op1(5 downto 0)))    when  op_alu=SRAV   else 
        to_StdLogicVector(to_bitvector(op1) srl  CONV_INTEGER(op2(10 downto 6)))   when  op_alu=SSRL   else 
        to_StdLogicVector(to_bitvector(op2) srl  CONV_INTEGER(op1(5 downto 0)))    when  op_alu=SRLV   else 
        op1 + op2;    -- default for ADDU,ADDIU,LBU,LW,SW,SB,BEQ,BGEZ,BLEZ,BNE    

end alu;

--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
--BI/DI: Barreira de registradores da busca 
--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_unsigned.all;
use IEEE.std_logic_arith.all;
use work.p_MRstd.all;


entity BIDI is
		port(ck, rst, ce : in std_logic;
				NPCin : in  STD_LOGIC_VECTOR (31 downto 0);
				NPCout : out STD_LOGIC_VECTOR (31 downto 0);
				IRin : in  STD_LOGIC_VECTOR (31 downto 0);
				IRout : out STD_LOGIC_VECTOR (31 downto 0)
		);
end BIDI;

architecture BIDI of BIDI is
begin

RNPC: entity work.regnbit port map(ck=>ck, rst=>rst, ce=>ce, D=>NPCin, Q=>NPCout);

RIR: entity work.regnbit  port map(ck=>ck, rst=>rst, ce=>ce, D=>IRin, Q=>IRout);

end BIDI;

--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
--DI/EX: Barreira de registradores da decodificação
--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_unsigned.all;
use IEEE.std_logic_arith.all;
use work.p_MRstd.all;


entity DIEX is
		port(ck, rst, ce : in std_logic;
				AUXIin: in STD_LOGIC_VECTOR (2 downto 0);
				AUXIout: out STD_LOGIC_VECTOR (2 downto 0);
				MINSin : in	microinstruction;
				MINSout : out microinstruction;
				NPCin : in  STD_LOGIC_VECTOR (31 downto 0);
				NPCout : out STD_LOGIC_VECTOR (31 downto 0);
				R1in : in  STD_LOGIC_VECTOR (31 downto 0);
				R1out : out STD_LOGIC_VECTOR (31 downto 0);
				R2in : in  STD_LOGIC_VECTOR (31 downto 0);
				R2out : out STD_LOGIC_VECTOR (31 downto 0);
				IMEDin : in  STD_LOGIC_VECTOR (31 downto 0);
				IMEDout : out STD_LOGIC_VECTOR (31 downto 0);
				SEG_Rin : in  STD_LOGIC_VECTOR (4 downto 0);
				SEG_Rout : out STD_LOGIC_VECTOR (4 downto 0);
				SEG_IMin : in  STD_LOGIC_VECTOR (4 downto 0);
				SEG_IMout : out STD_LOGIC_VECTOR (4 downto 0)
		);
end DIEX;

architecture DIEX of DIEX is
begin

RAUXI: entity work.regnbit generic map(REG_SIZE => 2) port map(ck=>ck, rst=>rst, ce=>ce, D=>AUXIin, Q=>AUXIout);

RMINS: entity work.regmins port map(ck=>ck, rst=>rst, ce=>ce, D=>MINSin, Q=>MINSout);

RNPC: entity work.regnbit port map(ck=>ck, rst=>rst, ce=>ce, D=>NPCin, Q=>NPCout);

REG_S: entity work.regnbit port map(ck=>ck, rst=>rst, ce=>ce, D=>R1in, Q=>R1out);

REG_T: entity work.regnbit port map(ck=>ck, rst=>rst, ce=>ce, D=>R2in, Q=>R2out);

REG_IM: entity work.regnbit port map(ck=>ck, rst=>rst, ce=>ce, D=>IMEDin, Q=>IMEDout);

INST_SEG_R: entity work.regnbit generic map(REG_SIZE => 4) port map(ck=>ck, rst=>rst, ce=>ce, D => SEG_Rin, Q =>SEG_Rout);

INST_SEG_IM: entity work.regnbit generic map(REG_SIZE => 4) port map(ck=>ck, rst=>rst, ce=>ce, D=> SEG_IMin, Q =>SEG_IMout);

end DIEX;

--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
--EX/MEM: Barreira de registradores da execução
--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_unsigned.all;
use IEEE.std_logic_arith.all;
use work.p_MRstd.all;


entity EXMEM is
		port(ck, rst, ce : in std_logic;
				AUXIin: in STD_LOGIC_VECTOR (2 downto 0);
				AUXIout: out STD_LOGIC_VECTOR (2 downto 0);
				MINSin : in	microinstruction;
				MINSout : out microinstruction;
				NPCin : in  STD_LOGIC_VECTOR (31 downto 0);
				NPCout : out STD_LOGIC_VECTOR (31 downto 0);
				ALUin : in  STD_LOGIC_VECTOR (31 downto 0);
				ALUout : out STD_LOGIC_VECTOR (31 downto 0);
				SALTAin : in  STD_LOGIC;
				SALTAout : out STD_LOGIC;
				R2in : in  STD_LOGIC_VECTOR (31 downto 0);
				R2out : out STD_LOGIC_VECTOR (31 downto 0);
				SEG_RDin : in  STD_LOGIC_VECTOR (4 downto 0);
				SEG_RDout : out STD_LOGIC_VECTOR (4 downto 0)
		);
end EXMEM;

architecture EXMEM of EXMEM is
begin

RAUXI: entity work.regnbit generic map(REG_SIZE => 2) port map(ck=>ck, rst=>rst, ce=>ce, D=>AUXIin, Q=>AUXIout);

RMINS: entity work.regmins port map(ck=>ck, rst=>rst, ce=>ce, D=>MINSin, Q=>MINSout);

RNPC: entity work.regnbit port map(ck=>ck, rst=>rst, ce=>ce, D=>NPCin, Q=>NPCout);

RALU: entity work.regnbit  port map(ck=>ck, rst=>rst, ce=>ce, D=>ALUin, Q=>ALUout);

RSALTA: entity work.regbit port map(ck=>ck, rst=>rst, ce=>ce, D=>SALTAin, Q=>SALTAout);

REG_T: entity work.regnbit port map(ck=>ck, rst=>rst, ce=>ce, D=>R2in, Q=>R2out);

INST_SEG_RD: entity work.regnbit generic map(REG_SIZE => 4) port map(ck=>ck, rst=>rst, ce=>ce, D => SEG_RDin, Q =>SEG_RDout);

end EXMEM;

--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
--MEM/ER: Barreira de registradores da escrita no REGBANK
--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_unsigned.all;
use IEEE.std_logic_arith.all;
use work.p_MRstd.all;


entity MEMER is
		port(ck, rst, ce : in std_logic;
				AUXIin: in STD_LOGIC_VECTOR (2 downto 0);
				AUXIout: out STD_LOGIC_VECTOR (2 downto 0);
				MINSin : in	microinstruction;
				MINSout : out microinstruction;
				NPCin : in  STD_LOGIC_VECTOR (31 downto 0);
				NPCout : out STD_LOGIC_VECTOR (31 downto 0);
				MEMin : in  STD_LOGIC_VECTOR (31 downto 0);
				MEMout : out STD_LOGIC_VECTOR (31 downto 0);
				SALTAin : in  STD_LOGIC;
				SALTAout : out STD_LOGIC;
				SEG_RDin : in  STD_LOGIC_VECTOR (4 downto 0);
				SEG_RDout : out STD_LOGIC_VECTOR (4 downto 0));
end MEMER;

architecture MEMER of MEMER is
begin

RAUXI: entity work.regnbit generic map(REG_SIZE => 2) port map(ck=>ck, rst=>rst, ce=>ce, D=>AUXIin, Q=>AUXIout);

RMINS: entity work.regmins port map(ck=>ck, rst=>rst, ce=>ce, D=>MINSin, Q=>MINSout);

RNPC: entity work.regnbit port map(ck=>ck, rst=>rst, ce=>ce, D=>NPCin, Q=>NPCout);

RMEM: entity work.regnbit  port map(ck=>ck, rst=>rst, ce=>ce, D=>MEMin, Q=>MEMout);

RSALTA: entity work.regbit port map(ck=>ck, rst=>rst, ce=>ce, D=>SALTAin, Q=>SALTAout);

INST_SEG_RD: entity work.regnbit generic map(REG_SIZE => 4) port map(ck=>ck, rst=>rst, ce=>ce, D => SEG_RDin, Q =>SEG_RDout);

end MEMER;

--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
-- Datapath structural description
--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
library IEEE;
use IEEE.Std_Logic_1164.all;
use IEEE.Std_Logic_signed.all; -- needed for comparison instructions SLTxx
use IEEE.Std_Logic_arith.all; -- needed for comparison instructions SLTxx
use work.p_MRstd.all;
   
entity datapath is
      port(  ck, rst :     in std_logic;
             i_address :   out std_logic_vector(31 downto 0);
             instruction : in std_logic_vector(31 downto 0);
             d_address :   out std_logic_vector(31 downto 0);
             data :        inout std_logic_vector(31 downto 0);  
             uinsD :       in microinstruction;
				 STSIG_out :	out std_logic_vector(2 downto 0);
             IR_OUT :      out std_logic_vector(31 downto 0)
          );
end datapath;

architecture datapath of datapath is
    signal incpc, pc, npc, npcE, npcM, npcR, IR,  result, R1, R2, RA, RB, RB2, RIN, ext16, cte_im, IMED, op1, op2, 
           outalu, RALU, MDR, mdr_int, dtpc : std_logic_vector(31 downto 0) := (others=> '0');
    signal adD, adS, seg_r, seg_im, seg_rdE, seg_rdM : std_logic_vector(4 downto 0) := (others=> '0');    
    signal inst_branch, inst_grupo1, inst_grupoI : std_logic;
	 signal auxiD, auxiE, auxiM, auxiR, stsigE: std_logic_vector (2 downto 0);
    signal salta, saltaM, saltaR : std_logic := '0';
	 signal uinsE, uinsM, uinsR : microinstruction;
begin

   -- auxiliary signals 
   inst_branch  <= '1' when uinsD.i=BEQ or uinsD.i=BGEZ or uinsD.i=BLEZ or uinsD.i=BNE else 
                  '0';
                  
   inst_grupo1  <= '1' when uinsD.i=ADDU or uinsD.i=SUBU or uinsD.i=AAND
                         or uinsD.i=OOR or uinsD.i=XXOR or uinsD.i=NNOR else
                   '0';

   inst_grupoI  <= '1' when uinsD.i=ADDIU or uinsD.i=ANDI or uinsD.i=ORI or uinsD.i=XORI else
                   '0';
						 
	auxiD <= inst_branch & inst_grupo1 & inst_grupoI;

   --==============================================================================
   -- first_stage
   --==============================================================================
  
   incpc <= pc + 4;
	
	
	BIDI: entity work.BIDI port map(ck=>ck, rst=>rst, ce=>uinsD.CY1, NPCin => incpc, NPCout => npc,
												IRin => instruction, IRout => IR);

   IR_OUT <= ir ;    -- IR is the datapath output signal to carry the instruction
             
   i_address <= pc;  -- connects PC output to the instruction memory address bus
   
   
   --==============================================================================
   -- second stage
   --==============================================================================
                
   -- The then clause is only used for logic shifts with shamt field       
   adS <= IR(20 downto 16) when uinsD.i=SSLL or uinsD.i=SSRA or uinsD.i=SSRL else 
          IR(25 downto 21);
          
   REGS: entity work.reg_bank(reg_bank) port map
        (ck=>ck, rst=>rst, wreg=>uinsR.wreg, AdRs=>adS, AdRt=>ir(20 downto 16), adRD=>adD,  
         Rd=>RIN, R1=>R1, R2=>R2);
    
   -- sign extension 
   ext16 <=  x"FFFF" & IR(15 downto 0) when IR(15)='1' else
             x"0000" & IR(15 downto 0);
    
   -- Immediate constant
   cte_im <= ext16(29 downto 0)  & "00"     when auxiD(2)='1'     else
                -- branch address adjustment for word frontier
             "0000" & IR(25 downto 0) & "00" when uinsD.i=J or uinsD.i=JAL else
                -- J/JAL are word addressed. MSB four bits are defined at the ALU, not here!
             x"0000" & IR(15 downto 0) when uinsD.i=ANDI or uinsD.i=ORI  or uinsD.i=XORI else
                -- logic instructions with immediate operand are zero extended
             ext16;
                -- The default case is used by addiu, lbu, lw, sbu and sw instructions
             
   -- second stage registers
	
	DIEX:  entity work.DIEX port map(ck=>ck, rst=>rst, ce=>uinsD.CY2, AUXIin=>auxiD, AUXIout=>auxiE, MINSin=>uinsD, MINSout=>uinsE,
													NPCin=>npc , NPCout=>npcE, R1in=>R1, R1out=>RA, R2in=>R2, R2out=>RB, IMEDin=>cte_im, IMEDout=>IMED,
													SEG_Rin=>IR(15 downto 11), SEG_Rout=>seg_r, SEG_IMin=>IR(20 downto 16), SEG_IMout=>seg_im);
													
   --==============================================================================
   -- third stage
   --==============================================================================
                      
   -- select the first ALU operand                           
   op1 <= npcE  when auxiE(2)='1' else 
          RA; 
     
   -- select the second ALU operand
   op2 <= RB when auxiE(1)='1' or uinsE.i=SLTU or uinsE.i=SLT or uinsE.i=JR 
                  or uinsE.i=SLLV or uinsE.i=SRAV or uinsE.i=SRLV else 
          IMED; 
                 
   -- ALU instantiation
   inst_alu: entity work.alu port map (op1=>op1, op2=>op2, outalu=>outalu, op_alu=>uinsE.i);
	
	stsigE <= uinsE.ce & uinsE.rw & uinsE.bw;

	EXMEM: entity work.EXMEM  port map(ck=>ck, rst=>rst, ce=>uinsE.walu, AUXIin=>auxiE, AUXIout=>auxiM, MINSin=>uinsE, MINSout=>uinsM, 
													NPCin=>npcE, NPCout=>npcM, ALUin =>outalu, ALUout=>RALU, SALTAin=>salta, SALTAout=>saltaM,
													R2in=>RB, R2out=>RB2, SEG_RDin=>seg_rdE, SEG_RDout=>seg_rdM);	
 
   -- evaluation of conditions to take the branch instructions
   salta <=  '1' when ( (RA=RB  and uinsE.i=BEQ)  or (RA>=0  and uinsE.i=BGEZ) or
                        (RA<=0  and uinsE.i=BLEZ) or (RA/=RB and uinsE.i=BNE) )  else
             '0';
				 
	-- register bank write address selection
	seg_rdE <= "11111"               when uinsE.i=JAL else -- JAL writes in register $31
         seg_r       when auxiE(1)='1' or uinsE.i=SLTU or uinsE.i=SLT
                                                     or uinsE.i=JALR  
						     or uinsE.i=SSLL or uinsE.i=SLLV
						     or uinsE.i=SSRA or uinsE.i=SRAV
						     or uinsE.i=SSRL or uinsE.i=SRLV
                                                     else
         seg_im -- inst_grupoI='1' or uins.i=SLTIU or uins.i=SLTI 
        ;                 -- or uins.i=LW or  uins.i=LBU  or uins.i=LUI, or default
                  
             
   --==============================================================================
   -- fourth stage
   --==============================================================================
     
   d_address <= RALU;
    
   -- tristate to control memory write    
   data <= RB2 when (uinsM.ce='1' and uinsM.rw='0') else (others=>'Z');  

   -- single byte reading from memory  -- SUPONDO LITTLE ENDIAN
   mdr_int <= data when uinsM.i=LW  else
              x"000000" & data(7 downto 0) when uinsM.i=LBU else
				  RALU;              
  
	MEMER: entity work.MEMER  port map(ck=>ck, rst=>rst, ce=>'1', AUXIin=>auxiM, AUXIout=>auxiR, MINSin=>uinsM, MINSout=>uinsR,
													NPCin=>npcM, NPCout=>npcR, MEMin=>mdr_int, MEMout=>MDR, SALTAin=>saltaM, SALTAout=>saltaR,
													SEG_RDin=>seg_rdM, SEG_RDout=>adD);
  
   result <= MDR;
	
	PULSE: entity work.pulsesig port map(ck=>ck, rst=>uinsM.ce, D=>uinsM, Q=>STSIG_out);
	
   --==============================================================================
   -- fifth stage
   --==============================================================================

   -- signal to be written into the register bank
   RIN <= npcR when (uinsR.i=JALR or uinsR.i=JAL) else result;
   
   -- register bank write address selection
    
   dtpc <= result when (auxiR(2)='1' and saltaR='1') or uinsR.i=J    or uinsR.i=JAL or uinsR.i=JALR or uinsR.i=JR  
           else incpc;
   
   -- Code memory starting address: beware of the OFFSET! 
   -- The one below (x"00400000") serves for code generated 
   -- by the MARS simulator
   rpc: entity work.regnbit generic map(INIT_VALUE=>x"00400000")   
                            port map(ck=>ck, rst=>rst, ce=>'1', D=>dtpc, Q=>pc);

end datapath;

--------------------------------------------------------------------------
--------------------------------------------------------------------------
--  Control Unit behavioral description 
--------------------------------------------------------------------------
--------------------------------------------------------------------------
library IEEE;
use IEEE.Std_Logic_1164.all;
use work.p_MRstd.all;

entity control_unit is
        port(   ck, rst : in std_logic;          
                uins : out microinstruction;
                ir : in std_logic_vector(31 downto 0)
             );
end control_unit;
                   
architecture control_unit of control_unit is
   signal i : inst_type;      
begin
      
    ----------------------------------------------------------------------------------------
    -- BLOCK (1/3) - INSTRUCTION DECODING and ALU operation definition.
    -- This block generates 1 Output Function of the Control Unit
    ----------------------------------------------------------------------------------------
    i <=   ADDU   when ir(31 downto 26)="000000" and ir(10 downto 0)="00000100001" else
           SUBU   when ir(31 downto 26)="000000" and ir(10 downto 0)="00000100011" else
           AAND   when ir(31 downto 26)="000000" and ir(10 downto 0)="00000100100" else
           OOR    when ir(31 downto 26)="000000" and ir(10 downto 0)="00000100101" else
           XXOR   when ir(31 downto 26)="000000" and ir(10 downto 0)="00000100110" else
           NNOR   when ir(31 downto 26)="000000" and ir(10 downto 0)="00000100111" else
			  NOP		when ir(31 downto 26)="000000" and ir(10 downto 0)="00000000000" else
           SSLL   when ir(31 downto 21)="00000000000" and ir(5 downto 0)="000000" else
           SLLV   when ir(31 downto 26)="000000" and ir(10 downto 0)="00000000100" else
           SSRA   when ir(31 downto 21)="00000000000" and ir(5 downto 0)="000011" else
           SRAV   when ir(31 downto 26)="000000" and ir(10 downto 0)="00000000111" else
           SSRL   when ir(31 downto 21)="00000000000" and ir(5 downto 0)="000010" else
           SRLV   when ir(31 downto 26)="000000" and ir(10 downto 0)="00000000110" else
           ADDIU  when ir(31 downto 26)="001001" else
           ANDI   when ir(31 downto 26)="001100" else
           ORI    when ir(31 downto 26)="001101" else
           XORI   when ir(31 downto 26)="001110" else
           LUI    when ir(31 downto 26)="001111" else
           LW     when ir(31 downto 26)="100011" else
           LBU    when ir(31 downto 26)="100100" else
           SW     when ir(31 downto 26)="101011" else
           SB     when ir(31 downto 26)="101000" else
           SLTU   when ir(31 downto 26)="000000" and ir(5 downto 0)="101011" else
           SLT    when ir(31 downto 26)="000000" and ir(5 downto 0)="101010" else
           SLTIU  when ir(31 downto 26)="001011"                             else
           SLTI   when ir(31 downto 26)="001010"                             else
           BEQ    when ir(31 downto 26)="000100" else
           BGEZ   when ir(31 downto 26)="000001" and ir(20 downto 16)="00001" else
           BLEZ   when ir(31 downto 26)="000110" and ir(20 downto 16)="00000" else
           BNE    when ir(31 downto 26)="000101" else
           J      when ir(31 downto 26)="000010" else
           JAL    when ir(31 downto 26)="000011" else
           JALR   when ir(31 downto 26)="000000"  and ir(20 downto 16)="00000"
                                           and ir(10 downto 0) = "00000001001" else
           JR     when ir(31 downto 26)="000000" and ir(20 downto 0)="000000000000000001000" else
           invalid_instruction ; -- IMPORTANT: default condition is invalid instruction;
        
    assert i /= invalid_instruction
          report "******************* INVALID INSTRUCTION *************"
          severity error;
                   
    uins.i <= i;    -- this instructs the alu to execute its expected operation, if any

    ----------------------------------------------------------------------------------------
    -- BLOCK (2/3) - DATAPATH REGISTERS load control signals generation.
    ----------------------------------------------------------------------------------------
    uins.CY1   <= '1';
            
    uins.CY2   <= '1';
  
    uins.walu  <= '1';
                
    uins.wmdr  <= '1' when i=LBU  or i=LW else '0';
  
    uins.wreg   <= '0' when i=SB or i=SW or i=BEQ or i=BGEZ or i=BLEZ or i=BNE or i=J or i=JR or i=NOP else   '1';
   
    uins.rw    <= '0' when i=SB or i=SW else  '1';
                  
    uins.ce    <= '1' when i=LBU  or i=LW or i=SB or i=SW  else '0';
    
    uins.bw    <= '0' when i=SB or i=LBU  else '1';
      
    uins.wpc   <= '1';
    
end control_unit;

--------------------------------------------------------------------------
-- Top-level instantiation of the MRstd Datapath and Control Unit
--------------------------------------------------------------------------
library IEEE;
use IEEE.Std_Logic_1164.all;
use work.p_MRstd.all;

entity MRstd is
    port( clock, reset: in std_logic;
          ce, rw, bw: out std_logic;
          i_address, d_address: out std_logic_vector(31 downto 0);
          instruction: in std_logic_vector(31 downto 0);
          data: inout std_logic_vector(31 downto 0));
end MRstd;

architecture MRstd of MRstd is
      signal IR: std_logic_vector(31 downto 0);
      signal uins, uinsM: microinstruction;
		signal stsig: std_logic_vector(2 downto 0);
		
 begin

     dp: entity work.datapath   
         port map( ck=>clock, rst=>reset, IR_OUT=>IR, uinsD=>uins, STSIG_out=>stsig, i_address=>i_address, 
                   instruction=>instruction, d_address=>d_address,  data=>data);

     ct: entity work.control_unit port map( ck=>clock, rst=>reset, IR=>IR, uins=>uins);
         
     ce <= stsig(2); 
     rw <= stsig(1); 
     bw <= stsig(0); 
     
end MRstd;