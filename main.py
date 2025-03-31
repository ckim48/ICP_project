import pymysql
from fastapi import FastAPI, File, UploadFile, Query
from fastapi.responses import FileResponse, JSONResponse
import os
from datetime import datetime
from typing import Optional

app = FastAPI()

@app.get("/personal-info")
def personal_info(id: str):
    conn_persinfo = pymysql.connect(host='justinkim0805.cafe24.com', user='justinkim0805', password='Justink0805^^', db='justinkim0805', charset='utf8mb4')
    cursor_persinfo = conn_persinfo.cursor()

    sql_persinfo = "SELECT full_name, status, email FROM personal_info WHERE id = %s"
    cursor_persinfo.execute(sql_persinfo, (id))

    res_persinfo = cursor_persinfo.fetchone()
    conn_persinfo.close()
    
    return res_persinfo

@app.get("/full-name")
def full_name(id: str):
    conn_fullname = pymysql.connect(host='justinkim0805.cafe24.com', user='justinkim0805', password='Justink0805^^', db='justinkim0805', charset='utf8mb4')
    cursor_fullname = conn_fullname.cursor()

    sql_fullname = "SELECT full_name FROM personal_info WHERE id = %s"
    cursor_fullname.execute(sql_fullname, (id))

    res_fullname = cursor_fullname.fetchone()
    conn_fullname.close()
    
    return res_fullname
    
@app.get("/gmail-address")
def gmail_address(id: str):
    conn_gmail = pymysql.connect(host='justinkim0805.cafe24.com', user='justinkim0805', password='Justink0805^^', db='justinkim0805', charset='utf8mb4')
    cursor_gmail = conn_gmail.cursor()

    sql_gmail = "SELECT email FROM personal_info WHERE id = %s"
    cursor_gmail.execute(sql_gmail, (id))

    res_gmail = cursor_gmail.fetchone()
    conn_gmail.close()
    
    return res_gmail

@app.get("/login-check")
def login_check(id: str, pw: str):
    conn_logincheck = pymysql.connect(host='justinkim0805.cafe24.com', user='justinkim0805', password='Justink0805^^', db='justinkim0805', charset='utf8mb4')
    cursor_logincheck = conn_logincheck.cursor()

    sql_logincheck = "SELECT id, password FROM personal_info WHERE id = %s AND password = %s"
    cursor_logincheck.execute(sql_logincheck, (id, pw))

    res_logincheck = cursor_logincheck.fetchone()
    count = cursor_logincheck.rowcount
    conn_logincheck.close()

    if (count > 0):
        return True
    else:
        return False

@app.get("/sign-up")
def sign_up(fname: str, id: str, pw: str, school: str, email: str, grade: str, status: str):
    conn_signup = pymysql.connect(host='justinkim0805.cafe24.com', user='justinkim0805', password='Justink0805^^', db='justinkim0805', charset='utf8mb4')
    cursor_signup = conn_signup.cursor()

    sql_signup = "INSERT INTO personal_info(full_name, id, password, school, email, grade, status) VALUES(%s, %s, %s, %s, %s, %s, %s)"
    
    cursor_signup.execute(sql_signup, (fname, id, pw, school, email, grade, status))

    conn_signup.commit()

    res_signup = cursor_signup.fetchall()
    conn_signup.close()

@app.get("/password-correspond")
def password_correspond(school: str, email: str):
    conn_pwcorrespond = pymysql.connect(host='justinkim0805.cafe24.com', user='justinkim0805', password='Justink0805^^', db='justinkim0805', charset='utf8mb4')
    cursor_pwcorrespond = conn_pwcorrespond.cursor()

    sql_pwcorrespond = "SELECT password FROM school_email_password WHERE school = %s AND email = %s"
    cursor_pwcorrespond.execute(sql_pwcorrespond, (school, email))

    res_pwcorrespond = cursor_pwcorrespond.fetchone()
    conn_pwcorrespond.close()

    return res_pwcorrespond

@app.get("/confirmed-check")
def confirmed_check(id: str):
    conn_confirmedcheck = pymysql.connect(host='justinkim0805.cafe24.com', user='justinkim0805', password='Justink0805^^', db='justinkim0805', charset='utf8mb4')
    cursor_confirmedcheck = conn_confirmedcheck.cursor()

    sql_confirmedcheck = "SELECT confirmed FROM personal_info WJERE id = %s"
    cursor_confirmedcheck.execute(sql_confirmedcheck, (id))
    
    res_confirmedcheck = cursor_confirmedcheck.fetchone()
    conn_confirmedcheck.close()
    
    if (res_confirmedcheck == 0):
        return False
    else:
        return True

@app.get("/helped")
def helped(id: str):
    conn_helped = pymysql.connect(host='justinkim0805.cafe24.com', user='justinkim0805', password='Justink0805^^', db='justinkim0805', charset='utf8mb4')
    cursor_helped = conn_helped.cursor()

    sql_helped = "SELECT lost_id, item, lost_date, found_date, helped_date, score_cnt FROM helped WHERE id = %s"
    cursor_helped.execute(sql_helped, (id))

    res_helped = cursor_helped.fetchall()
    conn_helped.close()

    helped_data = [
        {
            "Lost ID": row[0],
            "Item": row[1],
            "Lost Date": row[2],
            "Found Date": row[3],
            "Helped Date": row[4],
            "Score": row[5]
        } for row in res_helped
    ]
    
    return helped_data

@app.get("/lost")
def lost():
    conn_lost = pymysql.connect(host='justinkim0805.cafe24.com', user='justinkim0805', password='Justink0805^^', db='justinkim0805', charset='utf8mb4')
    cursor_lost = conn_lost.cursor()

    sql_lost = "SELECT * FROM lost"
    cursor_lost.execute(sql_lost)

    res_lost = cursor_lost.fetchall()
    conn_lost.close()

    lost_data = [
        {
            "ID": row[0],
            "Title": row[1],
            "Lost Date": row[2],
            "Lost Item": row[3],
            "Lost Location": row[4],
            "Item Description": row[5],
            "Delivery Preference": row[6],
            "Meet Up @": row[7],
            "Allow Suggestion": row[8],
            "Image File":row[9]
        } for row in res_lost
    ]
    
    return lost_data

@app.get("/found")
def found_items():
    conn_found = pymysql.connect(host='justinkim0805.cafe24.com', user='justinkim0805', password='Justink0805^^', db='justinkim0805', charset='utf8mb4')
    cursor_found = conn_found.cursor()

    sql_found = "SELECT * FROM found"
    cursor_found.execute(sql_found)

    res_found = cursor_found.fetchall()
    conn_found.close()

    found_data = [
        {
            "ID": row[0],
            "Title": row[1],
            "Found Date": row[2],
            "Found Item": row[3],
            "Found Location": row[4],
            "Found Description": row[5],
            "Delivery Preference": row[6],
            "Meet Up @": row[7],
            "Allow Suggestion": row[8],
            "Image File":row[9]
        } for row in res_found
    ]

    return found_data

'''
@app.post("/files")
async def create_file(file: bytes = File()):
    return {"file_size": len(file)}
'''

'''
@app.post("/uploadfile")
async def create_upload_file(user_id: str, shared_date: str, file: UploadFile):
    UPLOAD_DIR = "/home/ubuntu/photo"

    content = await file.read()
    filename = user_id+"_"+shared_date+".jpg"
    with open(os.path.join(UPLOAD_DIR, filename), "wb") as fp:
        fp.write(content)

    return {"filename": filename}
'''

@app.post("/share")
async def share(lfh: str, id: str, title: str, item_category: str, location: str, delivery_preference: str, meet_up_at: str, allow_suggestion: str, item_description: str, file: UploadFile):
    conn_share = pymysql.connect(host='justinkim0805.cafe24.com', user='justinkim0805', password='Justink0805^^', db='justinkim0805', charset='utf8mb4')
    cursor_share = conn_share.cursor()

    dt = datetime.now().strftime('%Y-%m-%d %H:%M:%S')

    UPLOAD_DIR = "/home/ubuntu/photo/"

    content = await file.read()
    img_file = lfh+"_"+id+"_"+dt.replace(" ", "_")+".jpg"
    with open(os.path.join(UPLOAD_DIR, img_file), "wb") as fp:
        fp.write(content)

    if(lfh=="LOST"):
        sql_share = "INSERT INTO lost(id, title, lost_date, lost_item, lost_location, delivery_preference, meet_up_at, allow_suggestion, lost_description, image_file) VALUES(%s, %s, %s, %s, %s, %s, %s, %s, %s, %s)"
        cursor_share.execute(sql_share,(id, title, dt, item_category, location, delivery_preference, meet_up_at, allow_suggestion, item_description, img_file))
    elif (lfh=="FOUND"):
        sql_share = "INSERT INTO found(id, title, found_date, found_item, found_location, delivery_preference, meet_up_at, allow_suggestion, found_description, image_file) VALUES(%s, %s, %s, %s, %s, %s, %s, %s, %s, %s)"
        cursor_share.execute(sql_share,(id, title, dt, item_category, location, delivery_preference, meet_up_at, allow_suggestion, item_description, img_file))

    conn_share.commit()

    res_share = cursor_share.fetchall()
    conn_share.close()

@app.get("/search")
def search(lfh: str, search_by: str, content: str):
    conn_search = pymysql.connect(host='justinkim0805.cafe24.com', user='justinkim0805', password='Justink0805^^', db='justinkim0805', charset='utf8mb4')
    cursor_search = conn_search.cursor()

    if (lfh=="LOST"):
        if (search_by == "ID"):
            sql_search = "SELECT * FROM lost WHERE id LIKE %s"
        elif (search_by == "DATE"):
            sql_search = "SELECT * FROM lost WHERE date LIKE %s"
        elif (search_by == "TITLE"):
            sql_search = "SELECT * FROM lost WHERE title LIKE %s"
        elif (search_by == "ITEM CATEGORY"):
            sql_search = "SELECT * FROM lost WHERE item_category LIKE %s"
        elif (search_by == "LOCATION"):
            sql_search = "SELECT * FROM lost WHERE location LIKE %s"
        elif (search_by == "ITEM DESCRIPTION"):
            sql_search = "SELECT * FROM lost WHERE item_description LIKE %s"
        else:
            return {"error": "No search results found"}

    elif (lfh=="FOUND"):
        if (search_by == "ID"):
            sql_search = "SELECT * FROM found WHERE id LIKE %s"
        elif (search_by == "DATE"):
            sql_search = "SELECT * FROM found WHERE date LIKE %s"
        elif (search_by == "TITLE"):
            sql_search = "SELECT * FROM found WHERE title LIKE %s"
        elif (search_by == "ITEM CATEGORY"):
            sql_search = "SELECT * FROM found WHERE item_category LIKE %s"
        elif (search_by == "LOCATION"):
            sql_search = "SELECT * FROM found WHERE location LIKE %s"
        elif (search_by == "ITEM DESCRIPTION"):
            sql_search = "SELECT * FROM found WHERE item_description LIKE %s"
        else:
            return {"error": "No search results found"}

    cursor_search.execute(sql_search, ('%'+content+'%'))

    res_search = cursor_search.fetchall()
    conn_search.close()

    search_data = [
        {
            "ID": row[0],
            "Title": row[1],
            "Date": row[2],
            "Item Category": row[3],
            "Location": row[4],
            "Delivery Preference": row[5],
            "Meet up @": row[6],
            "Allow Suggestion": row[7],
            "Item Description": row[8]
        } for row in res_search
    ]

    return search_data

@app.get("/load-image")
async def load_image(img_file: str):
    IMAGEDIR = "/home/ubuntu/photo/"
    file_path = os.path.join(IMAGEDIR, img_file)
    
    if os.path.isfile(file_path):
        return FileResponse(file_path, media_type="image/jpg")
    else:
        return JSONResponse(content={"error": "File not found"}, status_code=404)
