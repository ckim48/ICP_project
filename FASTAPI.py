import pymysql
from fastapi import FastAPI
from fastapi.responses import JSONResponse

app = FastAPI()

@app.get("/personal-info")
def personal_info(id: str):
    conn_persinfo = pymysql.connect(host='justinkim0805.cafe24.com', user='justinkim0805', password='Justink0805^^', db='justinkim0805', charset='utf8mb4')
    cursor_persinfo = conn_persinfo.cursor()

    sql_persinfo = "SELECT full_name, status, email FROM personal_info where id = %s"
    cursor_persinfo.execute(sql_persinfo, (id))

    res_persinfo = cursor_persinfo.fetchone()

    '''persinfo_data = [
        {
            "Full_Name": row[0],
            "Status": row[1],
            "Email": row[2]
        }
    ]'''
    conn_persinfo.close()
    return res_persinfo

@app.get("/login-check")
def login_check(id: str, pw: str):
    conn_logincheck = pymysql.connect(host='justinkim0805.cafe24.com', user='justinkim0805', password='Justink0805^^', db='justinkim0805', charset='utf8mb4')
    cursor_logincheck = conn_logincheck.cursor()

    sql_logincheck = "SELECT id, password FROM personal_info WHERE id=%s AND pw=%s"
    cursor_logincheck.execute(sql_logincheck, (id, pw))

    res_logincheck = cursor_logincheck.fetchone()
    count = cursor_logincheck.rowcount
    conn_logincheck.close()

    if (count > 0):
        return True
    else:
        return False

@app.get("/confirmed-check")
def confirmed_check(id: str):
    conn_confirmedcheck = pymysql.connect(host='justinkim0805.cafe24.com', user='justinkim0805', password='Justink0805^^', db='justinkim0805', charset='utf8mb4')
    cursor_confirmedcheck = conn_confirmedcheck.cursor()

    sql_confirmedcheck = "SELECT confirmed FROM personal_info where id=%s"
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

    sql_helped = "SELECT lost_id, item, lost_date, found_date, helped_date FROM helped where id = %s "
    cursor_helped.execute(sql_helped, (id))

    res_helped = cursor_helped.fetchall()
    '''helped_data = [
        {
            "ID": row[0],
            "Item": row[1],
            "Lost Date": row[2],
            "Found Date": row[3],
            "Helped Date": row[4]
        } for row in res_helped
    ]'''
    conn_helped.close()
    return res_helped

@app.get("/lost")
def lost(id: str):
    conn_lost = pymysql.connect(host='justinkim0805.cafe24.com', user='justinkim0805', password='Justink0805^^', db='justinkim0805', charset='utf8mb4')
    cursor_lost = conn_lost.cursor()

    sql_lost = "SELECT lost_item, lost_date, lost_location, lost_description FROM lost where id = %s"
    cursor_lost.execute(sql_lost, (id))

    res_lost = cursor_lost.fetchall()

    '''lost_data = [
        {
            "Item": row[0],
            "Date": row[1],
            "Location": row[2],
            "Description": row[3]
        } for row in res_lost
    ]'''
    conn_lost.close()
    return res_lost

@app.get("/found")
def found_items(id: str):
    conn_found =pymysql.connect(host='justinkim0805.cafe24.com', user='justinkim0805', password='Justink0805^^', db='justinkim0805', charset='utf8mb4')
    cursor_found = conn_found.cursor()

    sql_found = "SELECT found_item, found_date, found_location, found_description FROM found where id = %s"
    cursor_found.execute(sql_found, (id))

    res_found = cursor_found.fetchall()

    '''found_data = [
        {
            "Item": row[0],
            "Date": row[1],
            "Location": row[2],
            "Description": row[3]
        }
    ] '''
    conn_found.close()
    return res_found
