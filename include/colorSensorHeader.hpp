#include <Arduino.h>

class colorSensor {
    private:
    #define s0 53
    #define s1 52
    #define s2 51
    #define s3 50
    #define out 49

    struct Color {
        int rojo, verde, azul;
        Color(int rojo, int verde, int azul) : rojo(rojo), verde(verde), azul(azul) {}
    };

    struct FranjaColor {
        Color superior, inferior, original;
        FranjaColor(const Color& superior, const Color& inferior, const Color& original) : superior(superior), inferior(inferior), original(original) {}
        
        bool inFranja(Color c){
        return superior.rojo >= c.rojo && c.rojo >= inferior.rojo && 
                superior.azul >= c.azul && c.azul >= inferior.azul &&
                superior.verde >= c.verde && c.verde >= inferior.verde;
        }
    };

    FranjaColor franjas[9] = {
        FranjaColor(Color(9,17,13), Color(7,15,11), Color(8,16,12)), //rojo Claro - 8,16,12
        FranjaColor(Color(12,19,17), Color(10,17,15), Color(11,18,16)), //rojo Oscuro - 11,18,16
        FranjaColor(Color(12,21,18), Color(10,19,16), Color(11,20,17)), //rojo muy Oscuro - 11,20,17
        FranjaColor(Color(10,8,12), Color(8,6,10), Color(9,7,11)), //verde claro - 9,7,11
        FranjaColor(Color(12,10,13), Color(12,8,11), Color(11,9,12)), //verde oscuro - 11,9,12
        FranjaColor(Color(5,6,7), Color(3,4,5), Color(4,5,6)), //amarillo - 4,5,6
        FranjaColor(Color(11,9,6), Color(9,8,5), Color(10,9,6)), //azul - 10,9,6
        FranjaColor(Color(16,17,10), Color(14,15,8), Color(15,16,9)), //morado claro - 15,16,9
        FranjaColor(Color(19,21,19), Color(17,19,17), Color(18,20,18)) //morado oscuro - 18,20,18
    };
    
    public:
    void colorSensorInit();
    int getRojo();
    int getAzul();
    int getVerde();
    bool checkStopColor();
};
