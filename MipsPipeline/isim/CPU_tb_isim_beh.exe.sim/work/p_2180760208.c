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
extern char *STD_TEXTIO;
extern char *STD_STANDARD;



char *work_p_2180760208_sub_318745012_658403332(char *t1, char *t2, char *t3, int t4)
{
    char t5[128];
    char t6[24];
    char t7[16];
    char t12[16];
    char t17[8];
    char *t0;
    char *t8;
    char *t9;
    int t10;
    unsigned int t11;
    char *t13;
    int t14;
    char *t15;
    char *t16;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    unsigned char t24;
    char *t25;
    char *t26;
    char *t27;
    int t28;
    char *t29;
    int t30;
    int t31;
    char *t32;
    int t33;
    unsigned int t34;
    unsigned int t35;
    char *t36;
    unsigned char t37;
    char *t38;
    char *t39;
    char *t41;
    char *t42;
    static char *nl0[] = {&&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB5, &&LAB6, &&LAB7, &&LAB8, &&LAB9, &&LAB10, &&LAB11, &&LAB12, &&LAB13, &&LAB14, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB15, &&LAB16, &&LAB17, &&LAB18, &&LAB19, &&LAB20, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB15, &&LAB16, &&LAB17, &&LAB18, &&LAB19, &&LAB20, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21, &&LAB21};

LAB0:    t8 = (t7 + 0U);
    t9 = (t8 + 0U);
    *((int *)t9) = 1;
    t9 = (t8 + 4U);
    *((int *)t9) = 200;
    t9 = (t8 + 8U);
    *((int *)t9) = 1;
    t10 = (200 - 1);
    t11 = (t10 * 1);
    t11 = (t11 + 1);
    t9 = (t8 + 12U);
    *((unsigned int *)t9) = t11;
    t9 = (t12 + 0U);
    t13 = (t9 + 0U);
    *((int *)t13) = 3;
    t13 = (t9 + 4U);
    *((int *)t13) = 0;
    t13 = (t9 + 8U);
    *((int *)t13) = -1;
    t14 = (0 - 3);
    t11 = (t14 * -1);
    t11 = (t11 + 1);
    t13 = (t9 + 12U);
    *((unsigned int *)t13) = t11;
    t13 = (t5 + 4U);
    t15 = (t1 + 2952);
    t16 = (t13 + 88U);
    *((char **)t16) = t15;
    t18 = (t13 + 56U);
    *((char **)t18) = t17;
    xsi_type_set_default_value(t15, t17, 0);
    t19 = (t13 + 64U);
    t20 = (t15 + 80U);
    t21 = *((char **)t20);
    *((char **)t19) = t21;
    t22 = (t13 + 80U);
    *((unsigned int *)t22) = 4U;
    t23 = (t6 + 4U);
    t24 = (t3 != 0);
    if (t24 == 1)
        goto LAB3;

LAB2:    t25 = (t6 + 12U);
    *((char **)t25) = t7;
    t26 = (t6 + 20U);
    *((int *)t26) = t4;
    t27 = (t7 + 0U);
    t28 = *((int *)t27);
    t29 = (t7 + 8U);
    t30 = *((int *)t29);
    t31 = (t4 - t28);
    t11 = (t31 * t30);
    t32 = (t7 + 4U);
    t33 = *((int *)t32);
    xsi_vhdl_check_range_of_index(t28, t33, t30, t4);
    t34 = (1U * t11);
    t35 = (0 + t34);
    t36 = (t3 + t35);
    t37 = *((unsigned char *)t36);
    t38 = (char *)((nl0) + t37);
    goto **((char **)t38);

LAB3:    *((char **)t23) = t3;
    goto LAB2;

LAB4:    t8 = (t13 + 56U);
    t9 = *((char **)t8);
    t0 = xsi_get_transient_memory(4U);
    memcpy(t0, t9, 4U);
    t8 = (t2 + 0U);
    t15 = (t8 + 0U);
    *((int *)t15) = 3;
    t15 = (t8 + 4U);
    *((int *)t15) = 0;
    t15 = (t8 + 8U);
    *((int *)t15) = -1;
    t10 = (0 - 3);
    t11 = (t10 * -1);
    t11 = (t11 + 1);
    t15 = (t8 + 12U);
    *((unsigned int *)t15) = t11;

LAB1:    return t0;
LAB5:    t39 = (t1 + 4756);
    t41 = (t13 + 56U);
    t42 = *((char **)t41);
    t41 = (t42 + 0);
    memcpy(t41, t39, 4U);
    goto LAB4;

LAB6:    t8 = (t1 + 4760);
    t15 = (t13 + 56U);
    t16 = *((char **)t15);
    t15 = (t16 + 0);
    memcpy(t15, t8, 4U);
    goto LAB4;

LAB7:    t8 = (t1 + 4764);
    t15 = (t13 + 56U);
    t16 = *((char **)t15);
    t15 = (t16 + 0);
    memcpy(t15, t8, 4U);
    goto LAB4;

LAB8:    t8 = (t1 + 4768);
    t15 = (t13 + 56U);
    t16 = *((char **)t15);
    t15 = (t16 + 0);
    memcpy(t15, t8, 4U);
    goto LAB4;

LAB9:    t8 = (t1 + 4772);
    t15 = (t13 + 56U);
    t16 = *((char **)t15);
    t15 = (t16 + 0);
    memcpy(t15, t8, 4U);
    goto LAB4;

LAB10:    t8 = (t1 + 4776);
    t15 = (t13 + 56U);
    t16 = *((char **)t15);
    t15 = (t16 + 0);
    memcpy(t15, t8, 4U);
    goto LAB4;

LAB11:    t8 = (t1 + 4780);
    t15 = (t13 + 56U);
    t16 = *((char **)t15);
    t15 = (t16 + 0);
    memcpy(t15, t8, 4U);
    goto LAB4;

LAB12:    t8 = (t1 + 4784);
    t15 = (t13 + 56U);
    t16 = *((char **)t15);
    t15 = (t16 + 0);
    memcpy(t15, t8, 4U);
    goto LAB4;

LAB13:    t8 = (t1 + 4788);
    t15 = (t13 + 56U);
    t16 = *((char **)t15);
    t15 = (t16 + 0);
    memcpy(t15, t8, 4U);
    goto LAB4;

LAB14:    t8 = (t1 + 4792);
    t15 = (t13 + 56U);
    t16 = *((char **)t15);
    t15 = (t16 + 0);
    memcpy(t15, t8, 4U);
    goto LAB4;

LAB15:    t8 = (t1 + 4796);
    t15 = (t13 + 56U);
    t16 = *((char **)t15);
    t15 = (t16 + 0);
    memcpy(t15, t8, 4U);
    goto LAB4;

LAB16:    t8 = (t1 + 4800);
    t15 = (t13 + 56U);
    t16 = *((char **)t15);
    t15 = (t16 + 0);
    memcpy(t15, t8, 4U);
    goto LAB4;

LAB17:    t8 = (t1 + 4804);
    t15 = (t13 + 56U);
    t16 = *((char **)t15);
    t15 = (t16 + 0);
    memcpy(t15, t8, 4U);
    goto LAB4;

LAB18:    t8 = (t1 + 4808);
    t15 = (t13 + 56U);
    t16 = *((char **)t15);
    t15 = (t16 + 0);
    memcpy(t15, t8, 4U);
    goto LAB4;

LAB19:    t8 = (t1 + 4812);
    t15 = (t13 + 56U);
    t16 = *((char **)t15);
    t15 = (t16 + 0);
    memcpy(t15, t8, 4U);
    goto LAB4;

LAB20:    t8 = (t1 + 4816);
    t15 = (t13 + 56U);
    t16 = *((char **)t15);
    t15 = (t16 + 0);
    memcpy(t15, t8, 4U);
    goto LAB4;

LAB21:    t8 = (t1 + 4820);
    t15 = (t13 + 56U);
    t16 = *((char **)t15);
    t15 = (t16 + 0);
    memcpy(t15, t8, 4U);
    goto LAB4;

LAB22:;
}

void work_p_2180760208_sub_1271746325_658403332(char *t0, char *t1, char *t2, char *t3, char *t4)
{
    char t5[320];
    char t6[32];
    char t16[8];
    char t22[8];
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t23;
    char *t24;
    char *t25;
    unsigned char t26;
    char *t27;
    char *t28;
    int t29;
    int t30;
    int t31;
    int t32;
    int t33;
    int t34;
    int t35;
    int t36;
    int t37;
    int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned char t42;

LAB0:    t7 = (t5 + 4U);
    t8 = ((STD_TEXTIO) + 3280);
    t9 = (t7 + 56U);
    *((char **)t9) = t8;
    t10 = (t7 + 40U);
    *((char **)t10) = 0;
    t11 = (t7 + 64U);
    *((int *)t11) = 1;
    t12 = (t7 + 48U);
    *((char **)t12) = 0;
    t13 = (t5 + 76U);
    t14 = ((STD_STANDARD) + 192);
    t15 = (t13 + 88U);
    *((char **)t15) = t14;
    t17 = (t13 + 56U);
    *((char **)t17) = t16;
    xsi_type_set_default_value(t14, t16, 0);
    t18 = (t13 + 80U);
    *((unsigned int *)t18) = 1U;
    t19 = (t5 + 196U);
    t20 = ((STD_STANDARD) + 0);
    t21 = (t19 + 88U);
    *((char **)t21) = t20;
    t23 = (t19 + 56U);
    *((char **)t23) = t22;
    xsi_type_set_default_value(t20, t22, 0);
    t24 = (t19 + 80U);
    *((unsigned int *)t24) = 1U;
    t25 = (t6 + 4U);
    t26 = (t2 != 0);
    if (t26 == 1)
        goto LAB3;

LAB2:    t27 = (t6 + 12U);
    *((char **)t27) = t3;
    t28 = (t6 + 20U);
    *((char **)t28) = t4;
    std_textio_readline(STD_TEXTIO, t1, t2, t7);
    t8 = (t4 + 8U);
    t29 = *((int *)t8);
    t9 = (t4 + 4U);
    t30 = *((int *)t9);
    t10 = (t4 + 0U);
    t31 = *((int *)t10);
    t32 = t31;
    t33 = t30;

LAB4:    t34 = (t33 * t29);
    t35 = (t32 * t29);
    if (t35 <= t34)
        goto LAB5;

LAB7:    t8 = (t4 + 8U);
    t29 = *((int *)t8);
    t9 = (t4 + 4U);
    t30 = *((int *)t9);
    t10 = (t4 + 0U);
    t31 = *((int *)t10);
    t32 = t31;
    t33 = t30;

LAB9:    t34 = (t33 * t29);
    t35 = (t32 * t29);
    if (t35 <= t34)
        goto LAB10;

LAB12:
LAB1:    xsi_access_variable_delete(t7);
    return;
LAB3:    *((char **)t25) = t2;
    goto LAB2;

LAB5:    t11 = (t4 + 0U);
    t36 = *((int *)t11);
    t12 = (t4 + 8U);
    t37 = *((int *)t12);
    t38 = (t32 - t36);
    t39 = (t38 * t37);
    t40 = (1U * t39);
    t41 = (0 + t40);
    t14 = (t3 + t41);
    *((unsigned char *)t14) = (unsigned char)32;

LAB6:    if (t32 == t33)
        goto LAB7;

LAB8:    t30 = (t32 + t29);
    t32 = t30;
    goto LAB4;

LAB10:    t11 = (t13 + 56U);
    t12 = *((char **)t11);
    t11 = (t12 + 0);
    t14 = (t19 + 56U);
    t15 = *((char **)t14);
    t14 = (t15 + 0);
    std_textio_read7(STD_TEXTIO, t1, t7, t11, t14);
    t8 = (t13 + 56U);
    t9 = *((char **)t8);
    t26 = *((unsigned char *)t9);
    t8 = (t4 + 0U);
    t30 = *((int *)t8);
    t10 = (t4 + 8U);
    t31 = *((int *)t10);
    t34 = (t32 - t30);
    t39 = (t34 * t31);
    t40 = (1U * t39);
    t41 = (0 + t40);
    t11 = (t3 + t41);
    *((unsigned char *)t11) = t26;
    t8 = (t19 + 56U);
    t9 = *((char **)t8);
    t26 = *((unsigned char *)t9);
    t42 = (!(t26));
    if (t42 != 0)
        goto LAB13;

LAB15:
LAB14:
LAB11:    if (t32 == t33)
        goto LAB12;

LAB17:    t30 = (t32 + t29);
    t32 = t30;
    goto LAB9;

LAB13:    goto LAB12;

LAB16:    goto LAB14;

}


void ieee_p_2592010699_sub_3130575329_503743352();

void ieee_p_2592010699_sub_3130575329_503743352();

void ieee_p_2592010699_sub_3130575329_503743352();

void ieee_p_2592010699_sub_3130575329_503743352();

extern void work_p_2180760208_init()
{
	static char *se[] = {(void *)work_p_2180760208_sub_318745012_658403332,(void *)work_p_2180760208_sub_1271746325_658403332};
	xsi_register_didat("work_p_2180760208", "isim/CPU_tb_isim_beh.exe.sim/work/p_2180760208.didat");
	xsi_register_subprogram_executes(se);
	xsi_register_resolution_function(1, 2, (void *)ieee_p_2592010699_sub_3130575329_503743352, 3);
	xsi_register_resolution_function(2, 2, (void *)ieee_p_2592010699_sub_3130575329_503743352, 3);
	xsi_register_resolution_function(3, 2, (void *)ieee_p_2592010699_sub_3130575329_503743352, 3);
	xsi_register_resolution_function(4, 2, (void *)ieee_p_2592010699_sub_3130575329_503743352, 3);
}
