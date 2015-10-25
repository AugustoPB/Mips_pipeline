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

#include "xsi.h"

struct XSI_INFO xsi_info;

char *IEEE_P_3499444699;
char *WORK_P_2180760208;
char *IEEE_P_0774719531;
char *STD_TEXTIO;
char *IEEE_P_2592010699;
char *IEEE_P_3620187407;
char *STD_STANDARD;
char *WORK_P_0599277782;


int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    ieee_p_2592010699_init();
    ieee_p_3499444699_init();
    ieee_p_3620187407_init();
    std_textio_init();
    work_p_2180760208_init();
    work_p_0599277782_init();
    work_a_3613278437_3836892431_init();
    work_a_4249212076_3836892431_init();
    ieee_p_0774719531_init();
    work_a_0989759141_3196465293_init();
    work_a_0805485205_1823747887_init();
    work_a_2466334853_3196465293_init();
    work_a_4142356482_3196465293_init();
    work_a_3199023679_2995317124_init();
    work_a_3451703849_3196465293_init();
    work_a_3908871585_1900245990_init();
    work_a_3644721303_3196465293_init();
    work_a_2336629369_0980705600_init();
    work_a_0947263055_2086880523_init();
    work_a_3032556465_3204047050_init();
    work_a_0832606739_2725559894_init();
    work_a_4122829555_3482583765_init();
    work_a_2233512458_1547642186_init();
    work_a_1055719637_1127541820_init();
    work_a_2641966360_1023923642_init();
    work_a_1577618161_3196465293_init();
    work_a_2399776393_3027548060_init();
    work_a_3853510154_1351276808_init();
    work_a_2908437062_1062181665_init();
    work_a_1912994691_1912994691_init();


    xsi_register_tops("work_a_1912994691_1912994691");

    IEEE_P_3499444699 = xsi_get_engine_memory("ieee_p_3499444699");
    WORK_P_2180760208 = xsi_get_engine_memory("work_p_2180760208");
    IEEE_P_0774719531 = xsi_get_engine_memory("ieee_p_0774719531");
    STD_TEXTIO = xsi_get_engine_memory("std_textio");
    IEEE_P_2592010699 = xsi_get_engine_memory("ieee_p_2592010699");
    xsi_register_ieee_std_logic_1164(IEEE_P_2592010699);
    IEEE_P_3620187407 = xsi_get_engine_memory("ieee_p_3620187407");
    STD_STANDARD = xsi_get_engine_memory("std_standard");
    WORK_P_0599277782 = xsi_get_engine_memory("work_p_0599277782");

    return xsi_run_simulation(argc, argv);

}
