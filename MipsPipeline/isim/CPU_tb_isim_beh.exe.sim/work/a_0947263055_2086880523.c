/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Users/Augusto/Documents/GitHub/Mips_pipeline/MipsPipeline/mips_multiciclo.vhd";
extern char *IEEE_P_3620187407;



static void work_a_0947263055_2086880523_p_0(char *t0)
{
    unsigned char t1;
    unsigned char t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    unsigned char t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    unsigned char t12;
    unsigned char t13;
    unsigned char t14;
    char *t15;
    char *t16;
    unsigned int t17;
    unsigned char t18;
    unsigned char t19;
    char *t20;
    char *t21;
    unsigned int t22;
    unsigned char t23;
    unsigned char t24;
    char *t25;
    char *t26;
    unsigned int t27;
    unsigned char t28;
    unsigned char t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t39;
    char *t40;

LAB0:    xsi_set_current_line(559, ng0);
    t3 = (t0 + 1672U);
    t4 = *((char **)t3);
    t3 = (t0 + 5740U);
    t5 = (t0 + 1352U);
    t6 = *((char **)t5);
    t5 = (t0 + 5708U);
    t7 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t4, t3, t6, t5);
    if (t7 == 1)
        goto LAB8;

LAB9:    t8 = (t0 + 1672U);
    t9 = *((char **)t8);
    t8 = (t0 + 5740U);
    t10 = (t0 + 1512U);
    t11 = *((char **)t10);
    t10 = (t0 + 5724U);
    t12 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t9, t8, t11, t10);
    t2 = t12;

LAB10:    if (t2 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB3;

LAB4:
LAB17:    t35 = (t0 + 3552);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    t38 = (t37 + 56U);
    t39 = *((char **)t38);
    *((unsigned char *)t39) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t35);

LAB2:    t40 = (t0 + 3472);
    *((int *)t40) = 1;

LAB1:    return;
LAB3:    t30 = (t0 + 3552);
    t31 = (t30 + 56U);
    t32 = *((char **)t31);
    t33 = (t32 + 56U);
    t34 = *((char **)t33);
    *((unsigned char *)t34) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t30);
    goto LAB2;

LAB5:    t15 = (t0 + 1832U);
    t16 = *((char **)t15);
    t17 = (0 + 5U);
    t15 = (t16 + t17);
    t18 = *((unsigned char *)t15);
    t19 = (t18 == (unsigned char)18);
    if (t19 == 1)
        goto LAB14;

LAB15:    t20 = (t0 + 1832U);
    t21 = *((char **)t20);
    t22 = (0 + 5U);
    t20 = (t21 + t22);
    t23 = *((unsigned char *)t20);
    t24 = (t23 == (unsigned char)17);
    t14 = t24;

LAB16:    if (t14 == 1)
        goto LAB11;

LAB12:    t25 = (t0 + 1832U);
    t26 = *((char **)t25);
    t27 = (0 + 5U);
    t25 = (t26 + t27);
    t28 = *((unsigned char *)t25);
    t29 = (t28 == (unsigned char)16);
    t13 = t29;

LAB13:    t1 = t13;
    goto LAB7;

LAB8:    t2 = (unsigned char)1;
    goto LAB10;

LAB11:    t13 = (unsigned char)1;
    goto LAB13;

LAB14:    t14 = (unsigned char)1;
    goto LAB16;

LAB18:    goto LAB2;

}


extern void work_a_0947263055_2086880523_init()
{
	static char *pe[] = {(void *)work_a_0947263055_2086880523_p_0};
	xsi_register_didat("work_a_0947263055_2086880523", "isim/CPU_tb_isim_beh.exe.sim/work/a_0947263055_2086880523.didat");
	xsi_register_executes(pe);
}
