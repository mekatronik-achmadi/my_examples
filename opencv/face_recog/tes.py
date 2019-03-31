from uul_FRecog import UulFaceRec

list_nama = ["mas_Brewok", "mas_Mulus"]

fc = UulFaceRec("lbph",list_nama)

aface, alabel = fc.prepare_train('mydata/training')
fc.training(aface,alabel)

nama_img1 = fc.guessing("mydata/test/brewok.jpg")
nama_img2 = fc.guessing("mydata/test/mulus.jpg")

print("foto pertama adalah %s" % nama_img1)
print("foto kedua adalah %s" % nama_img2)
