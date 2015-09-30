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
static const char *ng0 = "C:/Users/Augusto/Documents/ARQ/Pipeline 2.0/MipsPipeline/mips_multiciclo.vhd";



static void work_a_2641966360_1023923642_p_0(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;

LAB0:    xsi_set_current_line(168, ng0);
    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)2);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 992U);
    t3 = xsi_signal_has_event(t1);
    if (t3 != 0)
        goto LAB5;

LAB6:
LAB3:    t1 = (t0 + 4304);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(169, ng0);
    t1 = (t0 + 4448);
    t5 = (t1 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB3;

LAB5:    xsi_set_current_line(172, ng0);
    t2 = (t0 + 1832U);
    t5 = *((char **)t2);
    t4 = *((unsigned char *)t5);
    t2 = (t0 + 4448);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = t4;
    xsi_driver_first_trans_fast(t2);
    goto LAB3;

}

static void work_a_2641966360_1023923642_p_1(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    unsigned int t7;
    unsigned char t8;
    unsigned char t9;
    char *t10;
    char *t11;
    unsigned int t12;
    unsigned char t13;
    unsigned char t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    static char *nl0[] = {&&LAB3, &&LAB4, &&LAB5};

LAB0:    xsi_set_current_line(179, ng0);
    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (char *)((nl0) + t3);
    goto **((char **)t1);

LAB2:    t1 = (t0 + 4320);
    *((int *)t1) = 1;

LAB1:    return;
LAB3:    xsi_set_current_line(181, ng0);
    t5 = (t0 + 1352U);
    t6 = *((char **)t5);
    t7 = (0 + 9U);
    t5 = (t6 + t7);
    t8 = *((unsigned char *)t5);
    t9 = (t8 == (unsigned char)19);
    if (t9 == 1)
        goto LAB9;

LAB10:    t10 = (t0 + 1352U);
    t11 = *((char **)t10);
    t12 = (0 + 9U);
    t10 = (t11 + t12);
    t13 = *((unsigned char *)t10);
    t14 = (t13 == (unsigned char)20);
    t4 = t14;

LAB11:    if (t4 != 0)
        goto LAB6;

LAB8:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t7 = (0 + 9U);
    t1 = (t2 + t7);
    t4 = *((unsigned char *)t1);
    t8 = (t4 == (unsigned char)17);
    if (t8 == 1)
        goto LAB14;

LAB15:    t5 = (t0 + 1352U);
    t6 = *((char **)t5);
    t12 = (0 + 9U);
    t5 = (t6 + t12);
    t9 = *((unsigned char *)t5);
    t13 = (t9 == (unsigned char)18);
    t3 = t13;

LAB16:    if (t3 != 0)
        goto LAB12;

LAB13:    xsi_set_current_line(186, ng0);
    t1 = (t0 + 4512);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t10 = *((char **)t6);
    *((unsigned char *)t10) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);

LAB7:    goto LAB2;

LAB4:    xsi_set_current_line(189, ng0);
    t1 = (t0 + 4512);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t10 = *((char **)t6);
    *((unsigned char *)t10) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB5:    xsi_set_current_line(190, ng0);
    t1 = (t0 + 4512);
    t2 = (t1 + 56U);
    t5 = *((char **)t2);
    t6 = (t5 + 56U);
    t10 = *((char **)t6);
    *((unsigned char *)t10) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB2;

LAB6:    xsi_set_current_line(182, ng0);
    t15 = (t0 + 4512);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    *((unsigned char *)t19) = (unsigned char)2;
    xsi_driver_first_trans_fast(t15);
    goto LAB7;

LAB9:    t4 = (unsigned char)1;
    goto LAB11;

LAB12:    xsi_set_current_line(184, ng0);
    t10 = (t0 + 4512);
    t11 = (t10 + 56U);
    t15 = *((char **)t11);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    *((unsigned char *)t17) = (unsigned char)1;
    xsi_driver_first_trans_fast(t10);
    goto LAB7;

LAB14:    t3 = (unsigned char)1;
    goto LAB16;

}

static void work_a_2641966360_1023923642_p_2(char *t0)
{
    unsigned char t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    unsigned char t7;
    unsigned char t8;
    unsigned char t9;
    char *t10;
    unsigned int t11;
    unsigned char t12;
    unsigned char t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned char t17;
    unsigned char t18;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned char t22;
    unsigned char t23;
    char *t24;
    char *t25;
    unsigned int t26;
    unsigned char t27;
    unsigned char t28;
    char *t29;
    char *t30;
    unsigned char t31;
    unsigned char t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t39;
    char *t40;
    char *t41;
    char *t42;

LAB0:    xsi_set_current_line(194, ng0);
    t3 = (t0 + 1672U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)0);
    if (t6 == 1)
        goto LAB8;

LAB9:    t2 = (unsigned char)0;

LAB10:    if (t2 == 1)
        goto LAB5;

LAB6:    t29 = (t0 + 1672U);
    t30 = *((char **)t29);
    t31 = *((unsigned char *)t30);
    t32 = (t31 == (unsigned char)1);
    t1 = t32;

LAB7:    if (t1 != 0)
        goto LAB3;

LAB4:
LAB20:    t37 = (t0 + 4576);
    t38 = (t37 + 56U);
    t39 = *((char **)t38);
    t40 = (t39 + 56U);
    t41 = *((char **)t40);
    *((unsigned char *)t41) = (unsigned char)2;
    xsi_driver_first_trans_delta(t37, 0U, 1, 0LL);

LAB2:    t42 = (t0 + 4336);
    *((int *)t42) = 1;

LAB1:    return;
LAB3:    t29 = (t0 + 4576);
    t33 = (t29 + 56U);
    t34 = *((char **)t33);
    t35 = (t34 + 56U);
    t36 = *((char **)t35);
    *((unsigned char *)t36) = (unsigned char)3;
    xsi_driver_first_trans_delta(t29, 0U, 1, 0LL);
    goto LAB2;

LAB5:    t1 = (unsigned char)1;
    goto LAB7;

LAB8:    t3 = (t0 + 1352U);
    t10 = *((char **)t3);
    t11 = (0 + 9U);
    t3 = (t10 + t11);
    t12 = *((unsigned char *)t3);
    t13 = (t12 == (unsigned char)20);
    if (t13 == 1)
        goto LAB17;

LAB18:    t14 = (t0 + 1352U);
    t15 = *((char **)t14);
    t16 = (0 + 9U);
    t14 = (t15 + t16);
    t17 = *((unsigned char *)t14);
    t18 = (t17 == (unsigned char)19);
    t9 = t18;

LAB19:    if (t9 == 1)
        goto LAB14;

LAB15:    t19 = (t0 + 1352U);
    t20 = *((char **)t19);
    t21 = (0 + 9U);
    t19 = (t20 + t21);
    t22 = *((unsigned char *)t19);
    t23 = (t22 == (unsigned char)17);
    t8 = t23;

LAB16:    if (t8 == 1)
        goto LAB11;

LAB12:    t24 = (t0 + 1352U);
    t25 = *((char **)t24);
    t26 = (0 + 9U);
    t24 = (t25 + t26);
    t27 = *((unsigned char *)t24);
    t28 = (t27 == (unsigned char)18);
    t7 = t28;

LAB13:    t2 = t7;
    goto LAB10;

LAB11:    t7 = (unsigned char)1;
    goto LAB13;

LAB14:    t8 = (unsigned char)1;
    goto LAB16;

LAB17:    t9 = (unsigned char)1;
    goto LAB19;

LAB21:    goto LAB2;

}

static void work_a_2641966360_1023923642_p_3(char *t0)
{
    char *t1;
    char *t2;
    unsigned int t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;

LAB0:    xsi_set_current_line(195, ng0);

LAB3:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t3 = (0 + 7U);
    t1 = (t2 + t3);
    t4 = *((unsigned char *)t1);
    t5 = (t0 + 4640);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = t4;
    xsi_driver_first_trans_delta(t5, 1U, 1, 0LL);

LAB2:    t10 = (t0 + 4352);
    *((int *)t10) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_2641966360_1023923642_p_4(char *t0)
{
    char *t1;
    char *t2;
    unsigned int t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;

LAB0:    xsi_set_current_line(196, ng0);

LAB3:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t3 = (0 + 8U);
    t1 = (t2 + t3);
    t4 = *((unsigned char *)t1);
    t5 = (t0 + 4704);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = t4;
    xsi_driver_first_trans_delta(t5, 2U, 1, 0LL);

LAB2:    t10 = (t0 + 4368);
    *((int *)t10) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_2641966360_1023923642_init()
{
	static char *pe[] = {(void *)work_a_2641966360_1023923642_p_0,(void *)work_a_2641966360_1023923642_p_1,(void *)work_a_2641966360_1023923642_p_2,(void *)work_a_2641966360_1023923642_p_3,(void *)work_a_2641966360_1023923642_p_4};
	xsi_register_didat("work_a_2641966360_1023923642", "isim/CPU_tb_isim_beh.exe.sim/work/a_2641966360_1023923642.didat");
	xsi_register_executes(pe);
}
