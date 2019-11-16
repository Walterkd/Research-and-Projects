# -*- coding: UTF-8 -*-
import xlrd
import cv2 as cv


def store_pictures(
	file1='G:\Handwriting\\image_overlap',  # 图片源地址
	file2='G:\Handwriting\\overlap_classify',  # 图片目的地址
	file3='G:\Handwriting\\pic_overlap_list.xlsx'):  # 特征记录表
	# file1 = “/Users/wangyoujia/Desktop/dataset_hw/hw_eval_proj/dataset_image_1”
	# file2 = “/Users/wangyoujia/Desktop/image-classification-keras/images_1”
	data = xlrd.open_workbook(file3)
	table = data.sheets()[0]
	nrows = table.nrows
	ncols = table.ncols
	"""
	# 汉字打分分类器
	for i in range(101, nrows):
		# left included with right excluded
		# 行序号比图片序号多1，所以从行序号减去1才是图片序号
		row = table.row_values(i)
		# row[0]表示图片序号数据，row[1]表示打分评价数据
		img = cv.imread(file1 + "/" + str(i-1).zfill(3) + ".jpg")
		if row[1] == 1:
			save_path = file2 + "/" + str(1) + "/" + str(i-1).zfill(3) + ".jpg"
			cv.imwrite(save_path, img)
		elif row[1] == 2:
			save_path = file2 + "/" + str(2) + "/" + str(i-1).zfill(3) + ".jpg"
			cv.imwrite(save_path, img)
		elif row[1] == 3:
			save_path = file2 +  "/" + str(3) + "/" + str(i-1).zfill(3) + ".jpg"
			cv.imwrite(save_path, img)
		elif row[1] == 4:
			save_path = file2 + "/" + str(4) + "/" + str(i-1).zfill(3) + ".jpg"
			cv.imwrite(save_path, img)
		else:
			save_path = file2 + "/" + str(5) + "/" + str(i-1).zfill(3) + ".jpg"
			cv.imwrite(save_path, img)
	"""
	# 判断汉字是否横向居中的分类器
	for i in range(0, 1001):  # gaidong
		row = table.row_values(i)
		img = cv.imread(file1 + "\\" + str(int(row[0])) + ".jpg")
		if row[1] == 0:
			save_path = file2 + "\\" + "not_overlap\\" + str(int(row[0])) + ".jpg"
			cv.imwrite(save_path, img)
		elif row[1] == 1:
			save_path = file2 + "\\" + "overlap\\" + str(int(row[0])) + ".jpg"
			cv.imwrite(save_path, img)
		else:
			continue


def main():
	store_pictures()
	print("Picture storage finished.")


if __name__=="__main__":
	main()

