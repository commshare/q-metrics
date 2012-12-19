#ifndef LOADER_H
#define LOADER_H

#include <vector>
#include <string>
#include <fftw3.h>
#include <opencv/ml.h>

// Esses cabecalhos sao necessarios para a leitura do tamanho
// do arquivo a partir do file descriptor: (POSIX)
// #include <sys/types.h>
// #include <sys/stat.h>

#include "global.h"
#include "img.hpp"
#include "artifacts.h"
#include "metric.h"
#include "debug.h"

using namespace std;

class Loader
{
        public:
                Loader (std::string,int,int,int);
                ~Loader();

                uchar*  getYUVBuffer() const;
                int     getTotalFrameNr() const;

                long    getFileSize(FILE *hFile);

                void    writeCodebook(std::string fCodebook, float DMOS, int frames_in_word, int word_sizeX, int word_sizeY);
                void    printFeatures(std::string fFeatures, int frames_in_word, int word_sizeX, int word_sizeY);
                double  predictMOS(std::string fCodebook, int K, int frames_in_word, int word_sizeX, int word_sizeY);
                void    compareLIVE(double predicted_value);

                void    callDebug();
                void    callDebug2(int i);
                void    callMetrics();
                void    callMetrics2(float DMOS);
                void    degradeVideo(std::string degradedName, std::string deg);
		void    degradecombineVideo(std::string degradedName, std::string deg, double *scale);

                void    showFrame(int i);
                void    dumpFrame(int i);
                void    degradecombineFrame(int i, std::string deg, double *scale);
		void    degradeFrame(int i, std::string deg);
                
                void    callDebug(int i);

        private:

                FILE * file;
                std::string fName;

                vector<cv::Mat> frameY;
                vector<cv::Mat> pckerr;

                int 	sizeX;          /// Numero de linhas  (altura)
                int 	sizeY;          /// Numero de colunas (largura)
                int 	format;         /// Formato do video (444,422,420,400)
                int     total_frame_nr;	/// Numero total de frames

                int     degrade_iteration;

                double  pool_frame(vector<double> v);
                int     count_lines(FILE *codebook);
};

#endif // LOADER_H
