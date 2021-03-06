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

import java.awt.Dimension;
import java.awt.Toolkit;
import java.io.File;
import java.util.prefs.Preferences;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;

public class FormFuses extends javax.swing.JFrame {
    
    private JFileChooser m_fileChooserFuses = new JFileChooser();

    private AVR m_avr;

    private JPanelFuses m_panelFuses;
    
    /** Creates new form FormFuses */
    public FormFuses(ActionThread actionThread) {
        
        m_fileChooserFuses.setFileFilter(new FileFilterXml());

        initComponents();

        setIconImage(Toolkit.getDefaultToolkit().getImage("AVR8_Burn-O-Mat_Icon_16.png"));

        m_panelFuses = new JPanelFuses(actionThread);
        add(m_panelFuses);

        loadPreferences();
    }
    
    public void setAVR(AVR avr) {

        m_avr = avr;

        setTitle(m_avr.getCaption() + " Fuses");

        m_panelFuses.setAVR(avr);

        validate();
        repaint();
    }
    
    public void savePreferences() {

        try {
            Preferences prefs = Preferences.userNodeForPackage(this.getClass());

            prefs.putInt("FormFuses_Width",getWidth());
            prefs.putInt("FormFuses_Height",getHeight());
            prefs.putInt("FormFuses_PosX",getX());
            prefs.putInt("FormFuses_PosY",getY());

            prefs.put("FileDialogLastDirFuses",m_fileChooserFuses.getCurrentDirectory().getPath());

            prefs.flush();
        } catch (Exception e) {
            System.err.println("Error while saving preferences: " + e.getMessage());
        }

    }

    public void loadPreferences() {

        try {
            Preferences prefs = Preferences.userNodeForPackage(this.getClass());

            int w, h;

            w = prefs.getInt("FormFuses_Width",600);
            h = prefs.getInt("FormFuses_Height",500);
            setSize(w,h);
            setPreferredSize(new Dimension(w,h));

            setLocation(prefs.getInt("FormFuses_PosX",100),
                        prefs.getInt("FormFuses_PosY",100));

            String s;

            s = prefs.get("FileDialogLastDirFuses","");
            if (s.length() > 0)
                m_fileChooserFuses.setCurrentDirectory(new File(s));

        } catch (Exception e) {
            System.err.println("Error while loading preferences: " + e.getMessage());
        }

    }
    
    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {
        java.awt.GridBagConstraints gridBagConstraints;

        jMenuBar1 = new javax.swing.JMenuBar();
        jMenu1 = new javax.swing.JMenu();
        jMenuItem1 = new javax.swing.JMenuItem();
        jMenuItem2 = new javax.swing.JMenuItem();
        jSeparator1 = new javax.swing.JSeparator();
        jMenuItem3 = new javax.swing.JMenuItem();

        setTitle("Fuses");
        getContentPane().setLayout(new java.awt.GridLayout(1, 1));

        jMenu1.setText("File");

        jMenuItem1.setText("save fuses to file");
        jMenuItem1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem1ActionPerformed(evt);
            }
        });
        jMenu1.add(jMenuItem1);

        jMenuItem2.setText("load fuses from file");
        jMenuItem2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem2ActionPerformed(evt);
            }
        });
        jMenu1.add(jMenuItem2);
        jMenu1.add(jSeparator1);

        jMenuItem3.setText("close");
        jMenuItem3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem3ActionPerformed(evt);
            }
        });
        jMenu1.add(jMenuItem3);

        jMenuBar1.add(jMenu1);

        setJMenuBar(jMenuBar1);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jMenuItem2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem2ActionPerformed
        
        try {
            
            int state = m_fileChooserFuses.showOpenDialog(this);
            if (state == JFileChooser.APPROVE_OPTION) {
                
                m_avr.loadFusesStateFromXml(m_fileChooserFuses.getSelectedFile());
            }
            
        } catch (Exception e) {
            JOptionPane.showMessageDialog(this,"Error reading fuses from file: " + e.getMessage());
        }

        m_panelFuses.fusesChanged();
        
    }//GEN-LAST:event_jMenuItem2ActionPerformed

    private void jMenuItem1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem1ActionPerformed
        
        try {
            
            int state = m_fileChooserFuses.showSaveDialog(this);
            if (state == JFileChooser.APPROVE_OPTION) {
                m_avr.saveFusesStateToXml(m_fileChooserFuses.getSelectedFile());
            }
            
        } catch (Exception e) {
            JOptionPane.showMessageDialog(this,"Error writing fuses to file! " + e.getMessage());
        }
    }//GEN-LAST:event_jMenuItem1ActionPerformed

    private void jMenuItem3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem3ActionPerformed
        
        setVisible(false);

    }//GEN-LAST:event_jMenuItem3ActionPerformed
            
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JMenu jMenu1;
    private javax.swing.JMenuBar jMenuBar1;
    private javax.swing.JMenuItem jMenuItem1;
    private javax.swing.JMenuItem jMenuItem2;
    private javax.swing.JMenuItem jMenuItem3;
    private javax.swing.JSeparator jSeparator1;
    // End of variables declaration//GEN-END:variables
    
}
