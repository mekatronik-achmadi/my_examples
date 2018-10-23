/*
 * Applet.java
 *
 * Created on 15. Juli 2007, 17:41
 */

package avr8_burn_o_mat;

import java.net.URL;

/**
 *
 * @author  torsten
 */
public class Applet extends java.applet.Applet {

    private String m_configUrl;

    /** Initializes the applet Applet */
    public void init() {

        FormMain.setLookAndFeel("Nimbus");

        try {

            String url = getDocumentBase().toString();
            final String appletPath = url.substring(0, url.lastIndexOf('/'));

            java.awt.EventQueue.invokeAndWait(new Runnable() {
                public void run() {
                    initComponents();
                    
                    add(new JPanelApplet(appletPath));
                }
            });
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
    
    /** This method is called from within the init() method to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        setLayout(new java.awt.GridLayout(1, 1));
    }// </editor-fold>//GEN-END:initComponents
    
    
    // Variables declaration - do not modify//GEN-BEGIN:variables
    // End of variables declaration//GEN-END:variables
    
}
