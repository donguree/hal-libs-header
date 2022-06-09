import PyPDF2
'''
image1 = Image.open('/home/lge123/linuxtv-ext-header/Documentation/source/water.PNG')
print(image1.mode)
image_inv = ImageOps.invert(image1)
inv_l = image_inv.convert('L')
image1.putalpha(inv_l)
image1.save('/home/lge123/linuxtv-ext-header/Documentation/source/convert.PNG')

wow = Image.open('/home/lge123/linuxtv-ext-header/Documentation/source/convert.PNG')
print(wow.mode)
im1 = wow.convert('RGB')

im1.save('/home/lge123/linuxtv-ext-header/Documentation/source/mark.pdf')
'''
from reportlab.pdfgen import canvas
from reportlab.lib.units import cm
content="LGE Confidential"
page= canvas.Canvas('mark.pdf', pagesize = (21*cm, 29.7*cm))
page.translate(18.0*cm, 0.0*cm)
page.setFont("Helvetica", 12)
#page.rotate(45)
page.setFillColorRGB(0.55,0.55,0.55)
page.setFillAlpha(0.3)
page.drawString(-1*cm, 1*cm, content)
page.save()

linux_pdf = open('build/singlepage.pdf','rb')
reader = PyPDF2.PdfFileReader(linux_pdf)
number_of_pages = reader.numPages
print(number_of_pages)
mark_pdf = open('mark.pdf','rb')
mark = PyPDF2.PdfFileReader(mark_pdf) 

merged_pdf = PyPDF2.PdfFileWriter()

for i in range(number_of_pages):
	ori = reader.getPage(i)
	ori.mergePage(mark.getPage(0))
	merged_pdf.addPage(ori)

merged_pdf.encrypt("linuxtv2021")
result = open('build/merged_singlepage.pdf','wb')
merged_pdf.write(result)
result.close()
linux_pdf.close()
mark_pdf.close()
