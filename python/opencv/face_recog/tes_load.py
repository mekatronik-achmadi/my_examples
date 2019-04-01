#!/usr/bin/python

from uul_FRecog import UulFaceRec
from os import path

list_nama = ["mas_Brewok", "mas_Mulus"]
haar = "haarcascade_frontalface_alt.xml"
filenm = "lbph_train_310319_1045"  + ".yml"

fc = UulFaceRec("lbph",list_nama,haar)

if path.exists(filenm):
    fc.load_train(filenm)
    print("file %s sudah di load" % filenm)
else:
    print("file %s tidak ada" % filenm)

nama_img1, r1 = fc.guessing("mydata/test/brewok.jpg")
nama_img2, r2 = fc.guessing("mydata/test/mulus.jpg")

res_img1 = fc.draw_marker("mydata/test/brewok.jpg",r1,nama_img1)
res_img2 = fc.draw_marker("mydata/test/mulus.jpg",r2,nama_img2)

print("foto pertama adalah %s" % nama_img1)
print("foto kedua adalah %s" % nama_img2)
