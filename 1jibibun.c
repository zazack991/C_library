#include <math.h>
#include <stdio.h>
#include <stdlib.h>
/*-------------------------------------------
    image_in:    入力画像配列
    image_out:    出力画像配列
    amp:        出力画像の利得
-----------------------------------------------------------------------------*/

int connect_degree(int d[9])
{
    int de[10];
    for(int i = 0; i<=8; i++){
        if(abs(d[i]) == 1){
            de[i] = 1;
        }else{
            de[i] = 0;
        }
    }
    if(abs(d[1]) == 1){
        de[9] == 1; 
    }else{
        de[9] = 0;
    }
    int s = 0;
    for(int k = 1; k<=7; k+=2){
        s += ((1 - de[k]) - (1 - de[k]) * (1 - de[k+1]) * (1 - de[k+2]));
    }
    return s;
}



void gradient(unsigned char image_in[Y_SIZE][X_SIZE], 
    unsigned char image_out[Y_SIZE][X_SIZE], float amp)
{
    /*static int cx[9] = { 0, 0, 0,    
                         0, 1, 0,    
                         0, 0,-1};   
    static int cy[9] = { 0, 0, 0,    
                         0, 0, 1,    
                         0,-1, 0};         */


    int        d[9];
    int        i, j, dat;
    //float    xx, yy, zz;

    for (i = 1; i < Y_SIZE-1; i++) {
        for (j = 1; j < X_SIZE-1; j++) {
            d[0] = image_in[i][j];
            d[1] = image_in[i][j+1];
            d[2] = image_in[i+1][j+1];
            d[3] = image_in[i+1][j];
            d[4] = image_in[i+1][j-1];
            d[5] = image_in[i][j-1];
            d[6] = image_in[i-1][j-1];
            d[7] = image_in[i-1][j];
            d[8] = image_in[i-1][j+1];
            /*xx = (float)(cx[0]*d[0] + cx[1]*d[1] + cx[2]*d[2]
                       + cx[3]*d[3] + cx[4]*d[4] + cx[5]*d[5]
                       + cx[6]*d[6] + cx[7]*d[7] + cx[8]*d[8]);
            yy = (float)(cy[0]*d[0] + cy[1]*d[1] + cy[2]*d[2]
                       + cy[3]*d[3] + cy[4]*d[4] + cy[5]*d[5]
                       + cy[6]*d[6] + cy[7]*d[7] + cy[8]*d[8]);
            zz = (float)(amp*sqrt(xx*xx+yy*yy));
            dat = (int)zz;
            if(dat > 255) dat = 255;
            image_out[i][j] = (char)dat;*/
        
            //条件1
            if(! (d[0] == 1)) {
                continue;
            }

            //条件2
            int s = 0;
            for(int k = 1; k<=7; k+=2){
                s += (1 - abs(d[k]));
            }
            if(! (s >= 1)){
                continue;
            }

            //条件3
            s = 0;
            for(int k = 1; k<=8; k++){
                s += (abs(d[k]));
            }
            if(! (s >= 2)){
                continue;
            }

            //条件4
            s = 0;
            for(int k = 1; k<=8; k++){
                if(d[k] == 1){
                    s++;
                }
            }
            if(! (s >= 1)){
                continue;
            }

            //条件5


        }
    }
}