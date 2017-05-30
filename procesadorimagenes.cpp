#include "procesadorimagenes.h"

ProcesadorImagenes::ProcesadorImagenes()
{
    namedWindow("vistas", CV_WINDOW_AUTOSIZE);
}

void ProcesadorImagenes::tomarFoto()
{
//    VideoCapture cap;
//    cap.open(0);

//    if(!cap.isOpened())
//        printf("error");

//    Mat frame;
//    while(waitKey(50) != 27 && cap.grab())
//    {
//        cap.retrieve(frame);
//        imshow("vistas", frame);
//    }
//    cap >> imagen;
//    imwrite("foto.jpg", frame);
//    frame.copyTo(imagen);
    imagen = imread("./img.jpg");
    imshow("vista", imagen);
}

void ProcesadorImagenes::convertirEscalaGrises()
{
    int R,G,B;
    Mat eg(imagen.rows, imagen.cols, CV_8UC1);
    for(int i = 0; i< imagen.cols; i++){
        for(int j = 0; j<imagen.rows; j++){
             B = imagen.data[imagen.cols*3*j + 3*i];
             G = imagen.data[imagen.cols*3*j + 3*i + 1];
             R = imagen.data[imagen.cols*3*j + 3*i + 2];
             eg.data[eg.cols*1*j + 1*i] = (R+G+B)/3;
        }
    }
    imshow("nuevaVista", eg);
    imwrite("EscalaGrises.jpg", eg);
    eg.copyTo(EscalaGrises);
}

void ProcesadorImagenes::defHistograma()
{
    for(int i = 0;i< 255; i++){
        histograma[i] = 0;
    }
    for(int i = 0; i<EscalaGrises.rows; i++){
        for(int j=0; j<EscalaGrises.rows; j++){
            histograma[EscalaGrises.data[EscalaGrises.cols*1*j + 1*i]]++;
        }
    }
}

int ProcesadorImagenes::otsu()
{
    int totalPixeles = EscalaGrises.cols * EscalaGrises.rows;
    int sum = 0;
    for(int i = 0; i < 256; i++){
        sum = sum + i*histograma[i];
    }
    int sumB = 0, wf = 0, wb = 0, varMax = 0, thresHold = 0;
    for(int i = 0; i < 256; i++){
        wb = wb + histograma[i];
        if(wb == 0){
            continue;
        }
        wf = totalPixeles - wb;
        if(wf == 0){
            break;
        }
        sumB = i*histograma[i];
        int mB = sumB / wb;
        int mF = (sum - sumB)/wf;
        int varBetween = wb*wf*(mB-mF)*(mB-mF);
        if(varBetween > varMax){
            varBetween = varBetween;
            thresHold = i;
        }
    }
    return thresHold;
}

void ProcesadorImagenes::convertirBinario()
{
    Mat bin(imagen.rows, imagen.cols, CV_8UC1);
    int umbral = this->otsu();
    printf("%d\n",umbral);
    int pixel = 0;
    for(int i = 0; i<EscalaGrises.cols; i++){
        for(int j = 0; j<EscalaGrises.rows; j++){
            pixel = EscalaGrises.data[EscalaGrises.cols*1*j + 1*i];
            if(pixel > umbral){
                bin.data[bin.cols*1*j + 1*i] = 255;
            }
            else{
                bin.data[bin.cols*1*j + 1*i] = 0;
            }
        }
    }
    imshow("Imagen Binaria", bin);
    imwrite("binario.jpg", bin);
    bin.copyTo(Binaria);
}
