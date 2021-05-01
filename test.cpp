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

    double DieL =20000_um, DieW = 10000_um;
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
        deviceL = 125_um;
        deviceW = 15_um;
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


var	mmi1 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi2 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi3 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi4 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi5 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi6 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi7 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi8 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi9 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi10 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi11 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi12 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi13 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi14 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi15 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi16 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi17 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi18 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi19 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi20 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi21 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi22 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi23 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi24 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi25 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi26 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi27 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi28 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi29 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi30 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi31 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi32 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi33 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi34 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi35 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi36 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi37 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi38 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi39 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi40 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi41 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi42 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi43 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi44 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi45 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi46 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi47 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi48 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi49 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi50 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi51 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi52 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi53 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi54 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi55 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi56 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi57 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi58 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi59 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi60 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi61 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi62 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi63 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);
var	mmi64 = NEW(MMI1by2,mmiL,mmiW,Sept,mmiTpL,taperW);

BLOCK{
mmi1.place();
}
BLOCK{
move(0,330_um,0,NOFLIP);  
mmi2.place();
}
BLOCK{
move(0,330_um*2,0,NOFLIP);  
mmi3.place();
}
BLOCK{
move(0,330_um*3,0,NOFLIP);  
mmi4.place();
}

BLOCK{
move(0,330_um*4,0,NOFLIP);  
mmi5.place();
}
BLOCK{
move(0,330_um*5,0,NOFLIP);  
mmi6.place();
}
BLOCK{
move(0,330_um*6,0,NOFLIP);  
mmi7.place();
}
BLOCK{
move(0,330_um*7,0,NOFLIP);  
mmi8.place();
}

BLOCK{
move(0,330_um*8,0,NOFLIP);
mmi9.place();
}
BLOCK{
move(0,330_um*9,0,NOFLIP);  
mmi10.place();
}
BLOCK{
move(0,330_um*10,0,NOFLIP);  
mmi11.place();
}
BLOCK{
move(0,330_um*11,0,NOFLIP);  
mmi12.place();
}

BLOCK{
move(0,330_um*12,0,NOFLIP);  
mmi13.place();
}
BLOCK{
move(0,330_um*13,0,NOFLIP);  
mmi14.place();
}
BLOCK{
move(0,330_um*14,0,NOFLIP);  
mmi15.place();
}
BLOCK{
move(0,330_um*15,0,NOFLIP);  
mmi16.place();
}
        // var stage11  = NEW(MMItree,brancharm1,16*brancharm2).place();
        // var stage21  = NEW(MMItree,brancharm1,8*brancharm2);
        // var stage22  = NEW(MMItree,brancharm1,8*brancharm2);
        // stage11.O_PORTS["out1"]>>stage21.O_PORTS["in0"];
        // stage11.O_PORTS["out0"]>>stage22.O_PORTS["in0"];
        // NEW(MMItt).place();
        // BLOCK {
        //     move(0,Sept,0,NOFLIP);
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
        // var stage21  = NEW(MMItree,brancharm1,brancharm2);
        // var stage22  = NEW(MMItree,brancharm1,brancharm2);
        // var stage23  = NEW(MMItree,brancharm1,brancharm2);
        // var stage24  = NEW(MMItree,brancharm1,brancharm2);

        // var stage31  = NEW(MMItree,brancharm1,brancharm2);
        // var stage32  = NEW(MMItree,brancharm1,brancharm2);
        // var stage33  = NEW(MMItree,brancharm1,brancharm2);
        // var stage34  = NEW(MMItree,brancharm1,brancharm2);
        // var stage35  = NEW(MMItree,brancharm1,brancharm2);
        // var stage36  = NEW(MMItree,brancharm1,brancharm2);
        // var stage37  = NEW(MMItree,brancharm1,brancharm2);
        // var stage38  = NEW(MMItree,brancharm1,brancharm2);
        
        // var stage41  = NEW(MMItree,brancharm1,brancharm2);
        // var stage42  = NEW(MMItree,brancharm1,brancharm2);
        // var stage43  = NEW(MMItree,brancharm1,brancharm2);
        // var stage44  = NEW(MMItree,brancharm1,brancharm2);
        // var stage45  = NEW(MMItree,brancharm1,brancharm2);
        // var stage46  = NEW(MMItree,brancharm1,brancharm2);
        // var stage47  = NEW(MMItree,brancharm1,brancharm2);
        // var stage48  = NEW(MMItree,brancharm1,brancharm2);
        // var stage49  = NEW(MMItree,brancharm1,brancharm2);
        // var stage410  = NEW(MMItree,brancharm1,brancharm2);
        // var stage411  = NEW(MMItree,brancharm1,brancharm2);
        // var stage412  = NEW(MMItree,brancharm1,brancharm2);
        // var stage413  = NEW(MMItree,brancharm1,brancharm2);
        // var stage414  = NEW(MMItree,brancharm1,brancharm2);
        // var stage415  = NEW(MMItree,brancharm1,brancharm2);
        // var stage416  = NEW(MMItree,brancharm1,brancharm2);

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