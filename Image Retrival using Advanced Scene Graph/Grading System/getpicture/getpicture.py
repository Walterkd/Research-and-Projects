# -*- coding: utf-8 -*-
# backend code for the marking mini-program
from flask import Flask,request
from flask import render_template
# from flask_bootstrap import Bootstrap
import pymysql
import json
import pandas as pd
app = Flask(__name__)
# bootstrap = Bootstrap(app)

#定义存储id和图片的list
p_goodsname = 0 #两张图片对比的结果
conn = pymysql.connect(host='localhost', port=3306, user='root', password='123456', database='mysql',
                       charset='utf8')
cur = conn.cursor()
sql = "SELECT * FROM handwrite"
cur.execute(sql)
u = cur.fetchall()
conn.close()

def initialization(initialnum):
    global picture, matrix
    global paixu2, paixu1
    matrix = []
    picture = []
    paixu1 = 0  # 冒泡排序的两个参数
    paixu2 = 0
    for i in range(initialnum, 21+initialnum, 3):
        matrix.append(u[i][1])
        picture.append(u[i][0])
    print(matrix)
    print(picture)

dinzu = 0
initialization(dinzu)

@app.route('/', methods=['GET', 'POST'])
def index():
    global paixu2, paixu1
    global picture, matrix
    global dinzu
    if request.method == 'GET':
        zuhe = picture[paixu2:paixu2+2]
        print(zuhe)
        print(paixu2)
        print(paixu1)
        picdata = json.dumps(zuhe)
        return picdata
    else:
        p_goodsname = request.values.get("goodsname")
        print(p_goodsname)
        print(type(p_goodsname))
        choose(paixu2, p_goodsname)
        paixu2 += 1
        if paixu2 == len(matrix)-1-paixu1:
            paixu2=0
            paixu1=paixu1+1

        if paixu1==6:
            dinzu = dinzu +1
            paixu1 = 0
            initialization(dinzu)
        return p_goodsname

#冒泡排序
def paixu(sameWord,decide):
    if decide ==1:
        swap(sameWord[0])

def choose(paixu2,p_goodsname):
    global matrix,picture
    if p_goodsname== '"1"':
        print("abc")
        matrix[paixu2],matrix[paixu2+1]=swap(matrix[paixu2],matrix[paixu2+1])
        picture[paixu2],picture[paixu2+1]=swap(picture[paixu2],picture[paixu2+1])
        print(matrix)

#交换数组中两个值的位置
def swap(t1,t2):
    return t2,t1

if __name__ == '__main__':
    app.run()



