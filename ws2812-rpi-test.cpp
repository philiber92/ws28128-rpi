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
#include <<unistd.h>

int main(int argc, char **argv){
    Color_t colors[] = {
            {255, 0, 0}, {0, 255, 0},
            {0, 0, 255}, {255, 255, 0},
            {0, 255, 255}, {255, 0, 255},
            {88, 88, 8}, {105, 105, 105},
            {138, 138, 138}, {139, 129, 76},
            {139, 10, 80}, {139, 58, 58},
            {255, 160, 122}, {34, 139, 34},
            {255, 64, 64}, {255, 255, 255}
    };
    NeoPixel *n=new NeoPixel(60);

    while(true) {
        for(unsigned i = 0; i < sizeof(colors); i++) {
            n->setPixelColor(59, colors[i]);
            n->setBrightness(0.05f);
            n->show();
            sleep(12);
        }
    }
    delete n;

    return 0;
}
