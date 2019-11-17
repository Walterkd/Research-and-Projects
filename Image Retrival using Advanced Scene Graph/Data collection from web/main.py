import os
import json
import random
from flask import Flask,request,jsonify,render_template,Response
import cv2


app = Flask(__name__)
basepath = os.path.dirname(__file__)
with open(basepath + '/static/relationships.json', 'r', encoding='utf-8') as f:
    relationships = json.loads(f.read())




# for id in relationships[0]['relationships']:
#     print(id)

# 设置允许的文件格式
ALLOWED_EXTENSIONS = set(['png', 'jpg', 'JPG', 'PNG', 'bmp'])


def allowed_file(filename):
    return '.' in filename and filename.rsplit('.', 1)[1] in ALLOWED_EXTENSIONS


@app.route('/save_image',methods=['POST','GET'])
def save_image():
    if request.method == 'POST':
        fs = request.files.getlist('file')
        type = request.form.get('type')
        basepath = os.path.dirname(__file__)

        upload_path = os.path.join(basepath + '/static/images/', type)

        if not os.path.exists(upload_path):
            os.mkdir(upload_path)
        for f in fs:

            filename = f.filename
            if not (f and allowed_file(f.filename)):
                return jsonify({"error": 1001, "msg": "请检查上传的图片类型，仅限于png、PNG、jpg、JPG、bmp"})

            save_path = os.path.join(upload_path + '/', filename)
            print(save_path)
            f.save(save_path)
        return jsonify({'msg':'保存成功'})

    elif request.method == 'GET':
        return render_template('/upload.html')


@app.route('/A',methods=['GET'])
def select_image_A():

    image_name = random.choice(os.listdir(basepath + '/static/images/A'))
    image_name_id = image_name.split('.')[0]

    upload_path = './static/images/A/' + image_name
    new_image_name = './static/images/AK/' + image_name  # 标框的文件夹

    image = cv2.imread(upload_path)  #读取源文件

    predicate = random.choice(relationships[int(image_name_id)]['relationships'])
    if predicate['object']['w'] * predicate['object']['h'] < predicate['subject']['w'] * predicate['subject']['h']:
        zuobiao = predicate['object']
    else:
        zuobiao = predicate['subject']
    w = zuobiao['w']
    h = zuobiao['h']
    x = zuobiao['x']
    y = zuobiao['y']

    cv2.rectangle(image, (x,y),(x+w,y+h), (0, 0, 255), 3)
    cv2.imwrite(new_image_name, image)

    return jsonify({'img_url':'/static/images/AK/' + image_name,'zuobiao':"{},{},{},{}".format(w,h,x,y),'image_id':image_name_id})


@app.route('/BC',methods=['GET'])
def select_image_BC():

    image_name = random.choice(os.listdir(basepath + '/static/images/BorC'))  #文件的名称
    image_name_id = image_name.split('.')[0]  #文件名的id

    upload_path = './static/images/BorC/' + image_name
    new_image_name = './static/images/BorCK/' + image_name  # 标框的文件夹


    image = cv2.imread(upload_path)

    predicate = random.choice(relationships[int(image_name_id)]['relationships'])
    if predicate['object']['w'] * predicate['object']['h'] < predicate['subject']['w'] * predicate['subject']['h']:
        zuobiao = predicate['object']
    else:
        zuobiao = predicate['subject']

    w = zuobiao['w']
    h = zuobiao['h']
    x = zuobiao['x']
    y = zuobiao['y']

    cv2.rectangle(image, (x, y), (x + w, y + h), (0, 0, 255), 3)

    cv2.imwrite(new_image_name, image)

    return jsonify({'img_url': '/static/images/BorCK/' + image_name, 'zuobiao': '{},{},{},{}'.format(w,h,x,y),'image_id':image_name_id})


@app.route('/index',methods=['GET'])
def index():
    return render_template('/index.html')


@app.route('/commit',methods=['POST'])
def save_result():
    # AB之间的相似度 > AC之间的相似度，那么
    # <Anchor: A，然后A的id，A的region的x，y，h，w；
    # Positive: B，然后B的id，B的region的x，y，h，w；
    # Negative: B，然后B的id，B的region的x，y，h，w；>
    writer = open(basepath + '/static/data.json', 'a+', encoding='utf-8')

    zuobiaoA = request.form.get('zuobiaoA')
    imageIDA = request.form.get('imageIDA')
    zuobiaoB = request.form.get('zuobiaoB')
    imageIDB = request.form.get('imageIDB')
    zuobiaoC = request.form.get('zuobiaoC')
    imageIDC = request.form.get('imageIDC')
    Positive = request.form.get('Positive')

    if not all([zuobiaoA,imageIDA,zuobiaoB,imageIDB,zuobiaoC,imageIDC]):
        return jsonify({'msg':'参数错误'})
    #w,h,x,y
    zuobiaoA_W = zuobiaoA.split(',')[0]
    zuobiaoA_H = zuobiaoA.split(',')[1]
    zuobiaoA_X = zuobiaoA.split(',')[2]
    zuobiaoA_Y = zuobiaoA.split(',')[3]

    zuobiaoB_W = zuobiaoB.split(',')[0]
    zuobiaoB_H = zuobiaoB.split(',')[1]
    zuobiaoB_X = zuobiaoB.split(',')[2]
    zuobiaoB_Y = zuobiaoB.split(',')[3]

    zuobiaoC_W = zuobiaoC.split(',')[0]
    zuobiaoC_H = zuobiaoC.split(',')[1]
    zuobiaoC_X = zuobiaoC.split(',')[2]
    zuobiaoC_Y = zuobiaoC.split(',')[3]


    if Positive == 'B': # AB>AC

        # data = <Anchor: A，然后A的id，A的region的x，y，h，w；Positive: B，然后B的id，B的region的x，y，h，w；Negative: B，然后B的id，B的region的x，y，h，w；>
        data = {'Anchor':'A','imageIDA':imageIDA,"zuobiaoA_W":zuobiaoA_W,"zuobiaoA_H":zuobiaoA_H,"zuobiaoA_X":zuobiaoA_X,"zuobiaoA_Y":zuobiaoA_Y,
                'Positive': 'B','imageIDB':imageIDB,"zuobiaoB_W":zuobiaoB_W,"zuobiaoB_H":zuobiaoB_H,"zuobiaoB_X":zuobiaoB_X,"zuobiaoB_Y":zuobiaoB_Y,
                'Negative':'C','imageIDC':imageIDC,"zuobiaoC_W":zuobiaoC_W,"zuobiaoC_H":zuobiaoC_H,"zuobiaoC_X":zuobiaoC_X,"zuobiaoC_Y":zuobiaoC_Y,
                }
        writer.write(json.dumps(data, ensure_ascii=False) + '\n')
        writer.close()
        return jsonify({'msg': '保存成功'})
    elif Positive == 'C':

        data = {'Anchor': 'A', 'imageIDA': imageIDA, "zuobiaoA_W": zuobiaoA_W, "zuobiaoA_H": zuobiaoA_H,
                "zuobiaoA_X": zuobiaoA_X, "zuobiaoA_Y": zuobiaoA_Y,
                'Negative': 'B', 'imageIDB': imageIDB, "zuobiaoB_W": zuobiaoB_W, "zuobiaoB_H": zuobiaoB_H,
                "zuobiaoB_X": zuobiaoB_X, "zuobiaoB_Y": zuobiaoB_Y,
                'Positive': 'C', 'imageIDC': imageIDC, "zuobiaoC_W": zuobiaoC_W, "zuobiaoC_H": zuobiaoC_H,
                "zuobiaoC_X": zuobiaoC_X, "zuobiaoC_Y": zuobiaoC_Y,
                }
        writer.write(json.dumps(data,ensure_ascii=False) + '\n')
        writer.close()
        return jsonify({'msg': '保存成功'})
    else:
        return jsonify({'msg':'参数错误'})



if __name__ == '__main__':
    print(app.url_map)
    app.run(host='0.0.0.0',port=5000)
