/*
    AVR8 Burn-O-Mat
 
    Copyright (C) 2009  Torsten Brischalle

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/
 */

package avr8_burn_o_mat;

import java.util.Vector;

public class OscillatorOptionsATmega8
extends OscillatorOptions {

    public OscillatorOptionsATmega8(Vector <Fuse> fuseList) {
        super(fuseList);
    }
    
    public JPanelOscillatorOptions createPanel(FusesEditor fusesEditor) {
        return new JPanelOscillatorOptionsATmega8(fusesEditor);
    }
    
}
