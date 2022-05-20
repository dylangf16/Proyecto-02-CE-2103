#include <iostream>
#include <fstream>
#include "Interfaz/mainwindow.h"
#include "Image.h"

Color::Color()
        : r(0), g(0), b(0)
{

}

Color::Color(float r, float g, float b)
        : r(r), g(g), b(b)
{
}

Color::~Color()
{
}

/**
 * Clase imagen, para crear objetos imagen tipo bmp
 * @param width ancho de la imagen
 * @param height altura de la imagen
 */
Image::Image(int width, int height)
        : m_width(width), m_height(height), m_colors(std::vector<Color>(width*height))
{

}

Image::~Image()
{

}

/**
 * Obtener el color de una coordenada de la imagen
 * @param x coordena en eje x
 * @param y coordenada en eje y
 * @return valor rgb del pixel seleccionado
 */
Color Image::GetColor(int x, int y) const
{
    return m_colors[y * m_width + x];
}

/**
 * Fija el color de un pixel de la imagen
 * @param color color que se desea fijar
 * @param x coordena en el eje x del pixel que se desea cambiar
 * @param y coordenada en el eje y del pixel que se desea cambiar
 */
void Image::setColor(const Color &color, int x, int y) {
    m_colors[y * m_width + x].r = color.r;
    m_colors[y * m_width + x].g = color.g;
    m_colors[y * m_width + x].b = color.b;
}

/**
 * Convierte valores RGB a HEX
 * @param r valor red del color
 * @param g valor green del color
 * @param b valor blue del color
 * @return valor HEX del color RGB recibido
 */
std::string conversionRGBtoHEX_2(int r, int g, int b){
    char hexColor[8];
    std::snprintf(hexColor, sizeof hexColor, "#%02x%02x%02x", r, g, b);
    std::string HEXvalue;
    HEXvalue += hexColor;
    return HEXvalue;
}

/**
 * Convierte valores de HEX a RGB
 * @param HEXvalue Valor HEX que se desea convertir
 * @param value Indicador de que color RGB se desea obtener
 * @return Valor R, G o B del color HEX
 */
int conversionHEXtoRGB_2(std::string HEXvalue, char value){
    char const *hexColor = HEXvalue.c_str();
    int rConversion, gConversion, bConversion, response;
    std::sscanf(hexColor, "#%02x%02x%02x", &rConversion, &gConversion, &bConversion);
    if(value == 'r'){
        response = rConversion;
        //cout << "r: " << response << endl;
    }
    else if(value == 'g'){
        response = gConversion;
        //cout << "g: " << response << endl;
    }
    else if(value == 'b'){
        response = bConversion;
        //cout << "b: " << response << endl;
    }
    return response;
}

/**
 * Convierte una clase imagen BMP a una matriz de vectores
 * @return matriz de vectores
 */
std::vector<std::vector<std::string>> Image::BMPtoMatrix() {
    const int width = m_width;
    const int height = m_height;
    std::vector<std::vector<std::string>> HEXvector;
    HEXvector.resize(height);
    for (int y = 0; y < height; y++) {
        HEXvector[y].resize(width);
        for (int x = 0; x < width; x++){
            HEXvector[y][x] = conversionRGBtoHEX_2(static_cast<unsigned char>(GetColor(x,y).r * 255.0f), static_cast<unsigned char>(GetColor(x,y).g * 255.0f),
                                                   static_cast<unsigned char>(GetColor(x,y).b * 255.0f));
        }
    }
    return HEXvector;
}

/**
 * Convierte una matriz en una clase imagen BMP
 * @param HEXvector matriz que se desea convertir
 */
void Image::matrixToBMP(std::vector<std::vector<std::string>> HEXvector) {
    m_height = HEXvector.size();
    m_width = HEXvector[0].size();

    m_colors.resize(m_width * m_height);

    for (int y = 0; y < m_height; y++) {
        for (int x = 0; x < m_width; x++) {
            m_colors[y * m_width + x].r = static_cast<float>(conversionHEXtoRGB_2(HEXvector[y][x], 'r')) / 255.0f;
            m_colors[y * m_width + x].g = static_cast<float>(conversionHEXtoRGB_2(HEXvector[y][x], 'g')) / 255.0f;
            m_colors[y * m_width + x].b = static_cast<float>(conversionHEXtoRGB_2(HEXvector[y][x], 'b')) / 255.0f;
        }
    }
}

/**
 * Crea un objeto imagen de una imagen BMP leida
 * @param path direccion de la imagen BMP
 */
void Image::Read(const char* path) {
    std::ifstream f;
    f.open(path, std::ios::in | std::ios::binary);

    if (!f.is_open()) {
        std::cout << "File could not be opened" << std::endl;
        return;
    }

    const int fileHeaderSize = 14;
    const int informationHeaderSize = 40;

    unsigned char fileHeader[fileHeaderSize];
    f.read(reinterpret_cast<char *>(fileHeader), fileHeaderSize);

    if(fileHeader[0] != 'B' || fileHeader[1] != 'M'){
        std::cout << "The specified path is no a bitmap image" << std::endl;
        f.close();
        return;
    }

    unsigned char informationHeader[informationHeaderSize];
    f.read(reinterpret_cast<char *>(informationHeader), informationHeaderSize);

    int fileSize = fileHeader[2] + (fileHeader[3] << 8) + (fileHeader[4] << 16) + (fileHeader[5] << 24);
    m_width = informationHeader[4] + (informationHeader[5] << 8) + (informationHeader[6] << 16) + (informationHeader[7] << 24);
    m_height = informationHeader[8] + (informationHeader[9] << 8) + (informationHeader[10] << 16) + (informationHeader[11] << 24);

    m_colors.resize(m_width * m_height);

    const int paddingAmount = ((4 - (m_width * 3) % 4) % 4);

    for(int y=0; y<m_height; y++){
        for(int x=0; x<m_width; x++){
            unsigned char color[3];
            f.read(reinterpret_cast<char*>(color),3);
            m_colors[y * m_width + x].r = static_cast<float>(color[2]) / 255.0f;
            m_colors[y * m_width + x].g = static_cast<float>(color[1]) / 255.0f;
            m_colors[y * m_width + x].b = static_cast<float>(color[0]) / 255.0f;
        }
        f.ignore(paddingAmount);
    }
    f.close();
    std::cout << "File read" << std::endl;
}

/**
 * Guarda un objeto de imagen como una imagen BMP
 * @param path direccion donde se desea guardar la imagen
 */
void Image::Export(const char *path) const {
    std::ofstream f;
    f.open(path, std::ios::out | std::ios::binary);

    if(!f.is_open())
    {
        std::cout << "File could not be opened";
        return;

    }

    unsigned char bmpPad[3] = {0,0,0};
    const int paddingAmount = ((4 - (m_width * 3) % 4) % 4);

    const int fileHeaderSize = 14;
    const int InformationHeaderSize = 40;
    const int fileSize = fileHeaderSize + InformationHeaderSize + m_width * m_height * 3 + paddingAmount * m_height;

    unsigned char fileHeader[fileHeaderSize];

    fileHeader[0] = 'B';
    fileHeader[1] = 'M';

    fileHeader[2] = fileSize;
    fileHeader[3] = fileSize >> 8;
    fileHeader[4] = fileSize >> 16;
    fileHeader[5] = fileSize >> 24;

    fileHeader[6] = 0;
    fileHeader[7] = 0;

    fileHeader[8] = 0;
    fileHeader[9] = 0;

    fileHeader[10] = 0;
    fileHeader[11] = 0;
    fileHeader[12] = 0;
    fileHeader[13] = 0;

    unsigned char informationHeader[InformationHeaderSize];

    informationHeader[0] = InformationHeaderSize;
    informationHeader[1] = 0;
    informationHeader[2] = 0;
    informationHeader[3] = 0;

    informationHeader[4] = m_width;
    informationHeader[5] = m_width >> 8;
    informationHeader[6] = m_width >> 16;
    informationHeader[7] = m_width >> 24;

    informationHeader[8] = m_height;
    informationHeader[9] = m_height >> 8;
    informationHeader[10] = m_height >> 16;
    informationHeader[11] = m_height >> 24;

    informationHeader[12] = 1;
    informationHeader[13] = 0;

    informationHeader[14] = 24;
    informationHeader[15] = 0;

    informationHeader[16] = 0;
    informationHeader[17] = 0;
    informationHeader[18] = 0;
    informationHeader[19] = 0;

    informationHeader[20] = 0;
    informationHeader[21] = 0;
    informationHeader[22] = 0;
    informationHeader[23] = 0;

    informationHeader[24] = 0;
    informationHeader[25] = 0;
    informationHeader[26] = 0;
    informationHeader[27] = 0;

    informationHeader[28] = 0;
    informationHeader[29] = 0;
    informationHeader[30] = 0;
    informationHeader[31] = 0;

    informationHeader[32] = 0;
    informationHeader[33] = 0;
    informationHeader[34] = 0;
    informationHeader[35] = 0;

    informationHeader[36] = 0;
    informationHeader[37] = 0;
    informationHeader[38] = 0;
    informationHeader[39] = 0;

    f.write(reinterpret_cast<char*>(fileHeader), fileHeaderSize);
    f.write(reinterpret_cast<char*>(informationHeader), InformationHeaderSize);

    for(int y =0; y < m_height; y++){
        for(int x = 0; x < m_width; x++){
            unsigned char r = static_cast<unsigned char>(GetColor(x,y).r * 255.0f);
            unsigned char g = static_cast<unsigned char>(GetColor(x,y).g * 255.0f);
            unsigned char b = static_cast<unsigned char>(GetColor(x,y).b * 255.0f);

            unsigned char color [] = {b,g,r};

            f.write(reinterpret_cast<char*>(color),3);

        }
        f.write(reinterpret_cast<char*>(bmpPad),paddingAmount);
    }
    f.close();

    std::cout << "File created" << endl;
}
