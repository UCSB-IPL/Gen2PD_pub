//
// Created by Yuan on 2018/11/8.
//

#ifndef JK_EXTENSION_PDK_DEMO_H
#define JK_EXTENSION_PDK_DEMO_H

#include "IPL_Extension.h"
#include "pdk.h"
#include "technology.h"




DECLARE_NEW_PDK(PDK_DEMO)


    DECLARE_WAVEGUIDES(
            , waveguide1)

    //Declare new component
    DECLARE_NEW_COMPONENT(MMI)

        //Declare component parameters

        //Declare component function
        MMI();
        void layout(int) override;

    END_DECLARE_NEW_COMPONENT(MMI)

    //Declare new component
    DECLARE_NEW_COMPONENT(MZI)

        //Declare component parameters

        //Declare component function
        MZI();
        void layout(int) override;

    END_DECLARE_NEW_COMPONENT(MMI)


    DECLARE_NEW_COMPONENT(CONNECTOR_SINE_BEND_EBEAM, CONNECTOR_SINE_BEND)
        explicit CONNECTOR_SINE_BEND_EBEAM();
        ComponentBase & Connector_Component(PortBase &, PortBase &) override;
    END_DECLARE_NEW_COMPONENT(CONNECTOR_SINE_BEND_EBEAM)



    //Declare new component
    DECLARE_NEW_COMPONENT(FiberArrayCoupler)
        
        //Declare component parameters
        int ArrayNum;
        double Pitch;
        double RotAngle;
        double ExtraTipLength;
        double ExtraWGLength;
        double TaperTipOffset;
        double TaperLength;
        double WGWidth;
        //Declare component function
        FiberArrayCoupler(int ArrayNum, double Pitch, double RotAngle, double ExtraTipLength, double ExtraWGLength );
        FiberArrayCoupler(double TaperTipOffset, double TaperLength, int ArrayNum, double Pitch, double RotAngle, double ExtraTipLength, double ExtraWGLength );
        FiberArrayCoupler(double TaperTipOffset, double TaperLength, double WGWidth, int ArrayNum, double Pitch, double RotAngle, double ExtraTipLength, double ExtraWGLength );
        void layout(int) override;
        
    END_DECLARE_NEW_COMPONENT(FiberArrayCoupler)
    

    //Declare new component
    DECLARE_NEW_COMPONENT(AllPassRingResonator)
        
        //Declare component parameters
        double RingRadius;
        double Gap;
        double Offset;
        WG_Structure * WG_struct;

        //Declare component function
        AllPassRingResonator(double RingRadius, double Gap, double Offset, WG_Structure * WG_struct);
        AllPassRingResonator(double RingRadius, double Gap, double Offset);
        void layout(int) override;
        
    END_DECLARE_NEW_COMPONENT(AllPassRingResonator)



END_DECLARE_NEW_PDK(PDK_DEMO)

#endif //JK_EXTENSION_PDK_DEMO_H
