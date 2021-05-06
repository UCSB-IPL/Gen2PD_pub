//
//

#include "IPL_Extension.h"
#include <string>
#include <vector>
#include <utility>


//#define GDS_FILENAME "mask_example.gds"
//#define MASK_NAME "JK_Extension"

#include "pdk_Xtech.h"

LOAD_PDK(PDK_Xtech);


void mask(int);

/* DO NOT MODIFY */
int main(int argc, char **argv) {
    setfont((char *)"caps.plf");
    msk_init();
    msk_add_sublayout(MASK_NAME, mask);
    msk_export(GDS_FILENAME);
    update_KLayout((char *)"KLayout 0.24.10");
}




void mask(int i) {

    double DieL =22000_um, DieW = 22000_um;
    double shiftx = 200_um, shifty = 90_um, stepperfine = 200e-6;

    BLOCK {
        skip(-DieL / 2);
        layer(L_Cleavemarks);
        sw(DieL, DieW);
    };
    BLOCK {
        org(-DieL / 2 + shiftx, DieW / 2 - shifty, 0, 0);
        NEW(STEPPER_1).place();
        skip(stepperfine);
        NEW(STEPPER_2).place();
        skip(stepperfine);
        NEW(EBL_LOCAL_MARK_TEMP, 100_um, 100_um, 1).place();

        org(-DieL / 2 + 4 * shiftx, DieW / 2 - shifty, 0, 0);
        NEW(STEPPER_1).place();
        skip(stepperfine);
        NEW(STEPPER_2).place();
        skip(stepperfine);
        NEW(EBL_LOCAL_MARK_TEMP, 100_um, 100_um, 0).place();

        org(DieL / 2 - shiftx, DieW / 2 - shifty, 0, 0);
        NEW(STEPPER_1).place();
        skip(-stepperfine);
        NEW(STEPPER_2).place();
        skip(-stepperfine);
        NEW(EBL_LOCAL_MARK_TEMP, 100_um, 100_um, 1).place();

        org(DieL / 2 - 4 * shiftx, DieW / 2 - shifty, 0, 0);
        NEW(STEPPER_1).place();
        skip(-stepperfine);
        NEW(STEPPER_2).place();
        skip(-stepperfine);
        NEW(EBL_LOCAL_MARK_TEMP, 100_um, 100_um, 0).place();

        org(-DieL / 2 + shiftx, -DieW / 2 + shifty, 0, 0);
        NEW(STEPPER_1).place();
        skip(stepperfine);
        NEW(STEPPER_2).place();
        skip(stepperfine);
        NEW(EBL_LOCAL_MARK_TEMP, 100_um, 100_um, 1).place();

        org(-DieL / 2 + 4 * shiftx, -DieW / 2 + shifty, 0, 0);
        NEW(STEPPER_1).place();
        skip(stepperfine);
        NEW(STEPPER_2).place();
        skip(stepperfine);
        NEW(EBL_LOCAL_MARK_TEMP, 100_um, 100_um, 0).place();

        org(DieL / 2 - shiftx, -DieW / 2 + shifty, 0, 0);
        NEW(STEPPER_1).place();
        skip(-stepperfine);
        NEW(STEPPER_2).place();
        skip(-stepperfine);
        NEW(EBL_LOCAL_MARK_TEMP, 100_um, 100_um, 1).place();

        org(DieL / 2 - 4 * shiftx, -DieW / 2 + shifty, 0, 0);
        NEW(STEPPER_1).place();
        skip(-stepperfine);
        NEW(STEPPER_2).place();
        skip(-stepperfine);
        NEW(EBL_LOCAL_MARK_TEMP, 100_um, 100_um, 0).place();

    };


    double Ystart = DieW/2, xstart = -DieL/2, xshift  = 600e-6, ydelta = -700e-6;
    double tempXorg = -5477.0_um, tempYorg =-300.00000_um;
    int fdevpointer = 1;
    double deviceL = 125_um, deviceW = 7_um, xalign = 10_um;
    //DBR mirror intilization
    double DBRTaperLength = 30e-6, DBRw =  1e-6 , DBRtop =  0.123e-6, DBRetched =0.123e-6, DBRnum_periods = 300, DBRein =  0.1e-6, DBRst = 200e-6;
    double NanoWdith = 10e-6, nanopitch = 0e-6, ffn = 0.666666666666666666, nanogap  =1e-6;
    int oderr = NanoWdith/nanopitch;
    double pt2 = 0.17_um,ff2 = 0.4, pt1 = 1.187_um,ff1=0.59;

    double R = 52_um, gap = 0.17_um, lcoalwg = 0.5_um;
    double HeaterRatio = 0.6, temp = (1-HeaterRatio)*2*M_PI/4;
    int turning = 6;
    double OverStep = 10_um, EtaperL = 30_um, padL = 100_um, overlapHeater = 1_um,nonheatersession = 6;
    double thedta = 20, tempteta = 0, lno = 0, widt = 0, ln1 = 0, dl = 0,overwg = 3_um, DeviceShift = 200e-6, DeviceXorg = -DieL / 2 + shiftx;
    double laserRidge = 3_um, ridgeshift = -0_um;

    double contrrolangle = 0;
    double cirw = 10_um,cirr = 40_um, rr = 105_um, arm = 10_um, width = 1_um,gapp = 5_um;
    double P_pad = 10_um, nholew = 40_um, nholerate  = 4,nviarate = 0.8, ncover = 3, ncoverL = 8;
    double YdeviceGap = 275_um,YdeviceGap2 =165_um;
    int everyrow1 = 6,everyrow2 = 50,everyrow = 1;
    double SOIwaveguideWidth  = 1_um;

    ///////////////////////////device intinalzition///////////////////////////
        deviceL = 250_um;
        deviceW = 25_um;
        laserRidge = 3_um;
        nanogap = 0;
    ///////////////////////////device intinalzition///////////////////////////

    // for(int i = 0;i<everyrow2;i++)

    // {

    // org(DeviceXorg, -DieW / 2 + 3*shifty+YdeviceGap2*i, 0, NOFLIP);

    //              NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle).place().O_PORTS["out0"]
    //             >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
    //             >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
    //             >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
    //             >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
    //             >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
    //             >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
    //             >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
    //             >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
    //             >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
    //             >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
    //             >>NEW(SAG_FP,deviceL,deviceW,3_um,laserRidge,contrrolangle);

    // }
        double brancharm1 = 100_um, brancharm2 = 100_um;
        double mmiL = 50_um,  mmiW = 12_um, Sept = 6_um, mmiTpL = 5_um, taperW = 2_um;


move(xstart,0,0,NOFLIP);
        NEW(MMItree2,127_um,7,127_um).place();


for(int i = 0;i<128;i++)
{
 
 BLOCK{
    adiabend(120_um, 14_deg, 1_um, 100);
    taper(50_um,1_um,6_um);
    move(-1_um,0,14_deg,NOFLIP);
    NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle).place().O_PORTS["out0"]
                >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
                >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
                >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
                >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
                >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
                >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
                >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
                >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
                >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
                >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
                >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
                >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
                >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
                >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
                >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
                >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
                >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
                >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
                >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
                >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
                >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
                >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
                >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
                >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
                >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
                >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
                >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
                >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
                >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle)
                >>NEW(SAG_FP,deviceL,deviceW,nanogap,laserRidge,contrrolangle);
    }
    offset(-127_um);
}

// BLOCK{
// move(0,165_um,0,NOFLIP);
// var cha2 = NEW(SW,1000_um).place();
// }

// move(xstart,Ystart+8*ydelta-10000_um,0,NOFLIP);
//         NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW).place();
//         BLOCK {
            
//                  NEW(SINE_BEND, brancharm1, brancharm2).place();
//         }
        // var stage11  = NEW(MMItree,brancharm1,16*brancharm2).place();
        // var stage21  = NEW(MMItree,brancharm1,8*brancharm2);
        // var stage22  = NEW(MMItree,brancharm1,8*brancharm2);
        // stage11.O_PORTS["out1"]>>stage21.O_PORTS["in0"];
        // stage11.O_PORTS["out0"]>>stage22.O_PORTS["in0"];
        // NEW(MMItt).place();
        // BLOCK {
        //     
        //          NEW(SINE_BEND, brancharm1, brancharm2).place();
        //          NEW(MMItt).place();
        // }
        // BLOCK {
        //         NEW(SINE_BEND, brancharm1, -brancharm2).place();
        //         NEW(MMItt).place();
        // }
        
        // NEW(SINE_BEND, brancharm1, brancharm2).place();

        // BLOCK {
        //     move(0,Sept,0,NOFLIP);
        // NEW(SINE_BEND, brancharm1, brancharm2).place();
        //  NEW(MMItree,brancharm1,brancharm2).place();
        // }
        // BLOCK {
        // //move(0,Sept,0,NOFLIP);
        // NEW(SINE_BEND, brancharm1, -brancharm2).place();
        //  NEW(MMItree,brancharm1,brancharm2).place();
        // }
        // var sta= NEW(MMItree,brancharm1,brancharm2);

        // NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW).place();
        // BLOCK {
        //     move(0,Sept,0,NOFLIP);
        // NEW(SINE_BEND, brancharm1, brancharm2).place();
        // }
        // BLOCK {
        // //move(0,Sept,0,NOFLIP);
        // NEW(SINE_BEND, brancharm1, -brancharm2).place();
        // }


    //    MMI1.O_PORTS["out1"]>> NEW(SINE_BEND, brancharm1, -brancharm2);
    //    MMI1.O_PORTS["out0"]>>NEW(CONNECTOR_SINE_BEND)>> MMI2.O_PORTS["in0"];

}