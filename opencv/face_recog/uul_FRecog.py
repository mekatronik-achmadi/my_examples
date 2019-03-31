import os
import sys
import cv2
import numpy as np

class UulFaceRec:

    dir_pre = "u"
    face_recog = None
    allmetode = ["lbph","fisher","eigen"]

    def __init__(self,cara,lstnama):
        self.nama = [""] + lstnama
        
        self.metode = cara
        
        if self.metode == "lbph":
            self.face_recog = cv2.face.LBPHFaceRecognizer_create()
        elif self.metode == "fisher":
            self.face_recog = cv2.face.FisherFaceRecognizer_create()
        elif self.metode == "eigen":
            self.face_recog = cv2.face.EigenFaceRecognizer_create()
        else:
            pesan = "metode %s tidak tersedia." % self.metode
            pesan += "yang tesedia saat ini:"
            for i in range(len(self.allmetode)):
                pesan += " %s |" % self.allmetode[i]
            print(pesan)

    def face_detect(self,img):
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        f_cas = cv2.CascadeClassifier('cascade/haarcascade_frontalface_alt.xml')
        face = f_cas.detectMultiScale(gray,scaleFactor=1.2,minNeighbors=5)

        if(len(face)==0):
            return None,None

        (x,y,w,h) = face[0]

        r_img = cv2.resize(gray[y:y+h, x:x+w],(150,200),interpolation=cv2.INTER_CUBIC)

        return r_img, face[0]

    def prepare_train(self,folder_path):
        dirs = os.listdir(folder_path)

        faces = []
        labels = []

        for dirname in dirs:
            if not dirname.startswith(self.dir_pre):
                continue

            label = int(dirname.replace(self.dir_pre,""))
            sub_dirpath = folder_path + "/" + dirname
            sub_img_name = os.listdir(sub_dirpath)

            for img_name in sub_img_name:
                if img_name.startswith("."):
                    continue

                img_path = sub_dirpath + "/" + img_name

                image = cv2.imread(img_path)
                cv2.resize(image, (400, 500))
                face, rect = self.face_detect(image)

                if face is not None:
                    faces.append(face)
                    labels.append(label)

        return faces, labels

    def training(self,u_faces, u_labels):
    	self.face_recog.train(u_faces, np.array(u_labels))

    def guessing(self,imgtest):
        face, rect = self.face_detect(cv2.imread(imgtest))
        label, confidence = self.face_recog.predict(face)
        label_nama = self.nama[label]

        return label_nama
