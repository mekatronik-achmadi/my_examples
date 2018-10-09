#! /usr/bin/python2
# -*- coding: utf-8 -*-

import os
import sys
from PyQt4 import QtCore, QtGui
from anboxh_ui import Ui_WinAnboxH

class AnboxH_main(QtGui.QMainWindow):
    def __init__ (self, parent=None):
        QtGui.QWidget.__init__(self, parent)
        self.ui = Ui_WinAnboxH()
        self.ui.setupUi(self)
        
        QtCore.QObject.connect(self.ui.btnFM, QtCore.SIGNAL("clicked()"), self.file_fm)
        QtCore.QObject.connect(self.ui.btnSend, QtCore.SIGNAL("clicked()"), self.file_send)
        QtCore.QObject.connect(self.ui.btnScan, QtCore.SIGNAL("clicked()"), self.file_scan)
        QtCore.QObject.connect(self.ui.btnBrowse, QtCore.SIGNAL("clicked()"), self.open_send)
        QtCore.QObject.connect(self.ui.btnReset, QtCore.SIGNAL("clicked()"), self.reset_send)
        QtCore.QObject.connect(self.ui.btnMgr, QtCore.SIGNAL("clicked()"), self.session_mgr)
        QtCore.QObject.connect(self.ui.btnStop, QtCore.SIGNAL("clicked()"), self.session_stop)
        QtCore.QObject.connect(self.ui.btnStart, QtCore.SIGNAL("clicked()"), self.session_start)
        
    def file_fm(self):
        bashcmd="anbox launch --action=android.intent.action.MAIN --package=com.android.documentsui --component=com.android.documentsui.FilesActivity --uri=content://com.android.externalstorage.documents/root/primary --type=vnd.android.document/root"
        os.system(bashcmd)
        
    def file_send(self):
        localfile= str(self.ui.txtLocal.text())
        remotepath = str(self.ui.txtRemote.text())
        
        bashcmd="anbox-push"
        bashcmd+=" "
        bashcmd+=localfile
        bashcmd+=" "
        bashcmd+=remotepath
        
        os.system(bashcmd)
        
    def file_scan(self):
        localfile= str(self.ui.txtLocal.text())
        remotepath = str(self.ui.txtRemote.text())
        
        bashcmd="anbox-scan"
        bashcmd+=" "
        bashcmd+=localfile
        bashcmd+=" "
        bashcmd+=remotepath
        
        os.system(bashcmd)
        
    def open_send(self):
        fileName=QtGui.QFileDialog.getOpenFileName(self,"Select File", QtCore.QString() )
        if fileName.isEmpty():
            return
            
        self.ui.txtLocal.setText(fileName)
        
    def reset_send(self):
        self.ui.txtRemote.setText("/sdcard/")
    
    def session_mgr(self):
        bashcmd="anbox launch --package=org.anbox.appmgr --component=org.anbox.appmgr.AppViewActivity"
        os.system(bashcmd)
        
    def session_start(self):
        bashcmd="anbox-start"
        os.system(bashcmd)
        
    def session_stop(self):
        bashcmd="anbox-stop"
        os.system(bashcmd)
        
if __name__ == "__main__":
    app = QtGui.QApplication(sys.argv)
    my_main_app = AnboxH_main()
    my_main_app.show()
    sys.exit(app.exec_())
