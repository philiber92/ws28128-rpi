/*
###############################################################################
#                                                                             #
# WS2812-RPi                                                                  #
# ==========                                                                  #
# A C++ library for driving WS2812 RGB LED's (known as 'NeoPixels' by         #
#     Adafruit) directly from a Raspberry Pi with accompanying Python wrapper #
# Copyright (C) 2014 Rob Kent                                                 #
#                                                                             #
# This program is free software: you can redistribute it and/or modify        #
# it under the terms of the GNU General Public License as published by        #
# the Free Software Foundation, either version 3 of the License, or           #
# (at your option) any later version.                                         #
#                                                                             #
# This program is distributed in the hope that it will be useful,             #
# but WITHOUT ANY WARRANTY; without even the implied warranty of              #
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               #
# GNU General Public License for more details.                                #
#                                                                             #
# You should have received a copy of the GNU General Public License           #
# along with this program.  If not, see <http://www.gnu.org/licenses/>.       #
#                                                                             #
###############################################################################
*/

#include "ws2812-rpi.h"

int main(int argc, char **argv){
    int number_of_led = 6;
    Color_t colors[number_of_led] = {
            colors->Color_t(255, 0, 0), colors->Color_t(255, 0, 0),
            colors->Color_t(255, 0, 0), colors->Color_t(255, 0, 0),
            colors->Color_t(255, 0, 0), colors->Color_t(255, 0, 0),
    };
    NeoPixel *n=new NeoPixel(number_of_led);

    while(true) {
        for(unsigned i = 1; i <= number_of_led; i++) {
            n->setPixelColor(i, colors[i-1]);
        }
        n->setBrightness(0.05f);
        n->show();
    }
    delete n;

    return 0;
}
