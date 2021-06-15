#  API 设计





三个调试用的api

请将localhost改为localhost

http://localhost:port/patient/printDatabaseInfo  输出当前数据库中所有信息（get请求）

http://localhost:port/patient/clearDatabase 清除数据已有的预约信息

http://localhost:port/patient/loadDatabase 启动数据库

http://localhost:port/patient/loadDatabase/clearAllPatients  清楚所有病患及预约

```

```







## 注册

目前来说不开放医生注册的，所有注册的都是患者，医生注册通过后台内置

### 请求 URL

```js
http://localhost:port/patient/register
```

### 请求方式

```js
POST
```

### 请求体

```js
{
  "name": "12312", 
  "pass": "pass1",
   "sex": "男",
   "date": "1998-01-01",
},
```

### 返回示例

```js
* 获取成功
  {
      "code": 1,
       "uid": “1212”
  }
* 获取失败
  {
    "code": 0,
    "msg": "some error information"
  }
```







## 患者/医生登陆

后台可以识别出来他们是医生还是患者，医生患者都可以登录

### 请求 URL

```js
http://localhost:port/patient/login
```

### 请求方式

```js
POST
```

### 请求体

```js
{
  "uid": "23231231",
  "pass": "pass1"
},
```

### 返回示例

```jsx
* 获取成功
{
    "code": 1,
    "data": {
        "age": 23,//年龄
        "background": "专治骨科",
        "date": "1998-03-03",//出生日期
        "department": "骨科",
        "isDoctor": true,//标志是否是医生
        "name": "田泽远",
        "restNum": 12,//剩余可预约数
        "sex": "男",
        "status": 1,//1表示工作中，0表示下班中，目前来说全是1
        "uid": "0"//该医生的uid
    }
}//医生登陆成功示范
{
    "code": 1,
    "data": {
        "age": 31,
        "date": "1990-01-01",
        "isDoctor": false,
        "name": "病人1号",
        "sex": "男",
        "uid": "3"//病人的uid
    }
}//病人登陆成功示范
* 获取失败
  {
    "code": 0,
    "msg": "用户已经注册，请更换用户名或登陆密码不正确"
     
  }
```







## 获取当前登录用户信息

当前登录用户（医生或患者）获得自己的信息，未登陆用户会出错

### 请求 URL

```js
http://localhost:port/patient/getPatientInfo
```

### 请求方式

```js
GET
```

### 返回示例

```js
* 获取成功
{
    "code": 1,
    "data": {
        "age": 31,
        "date": "1990-01-01",
        "isDoctor": false,
        "name": "病人1号",
        "sex": "男",
        "uid": "3"
    }
}//如果当前登陆的人是病人
{
    "code": 1,
    "data": {
        "age": 23,
        "background": "专治骨科",
        "date": "1998-03-03",
        "department": "骨科",
        "isDoctor": true,
        "name": "田泽远",
        "restNum": 12,
        "sex": "男",
        "status": 1,
        "uid": "0"
    }
}//如果当前登录的人是医生
* 获取失败//一般来说医生可以看所有人信息，但是患者只能看自己的信息
{
    "code": 0,
    "msg": "您现在还未登陆"
}
```









## 获得某医生信息

只能请求医生的信息，可以不登录即可查询

### 请求 URL

```js
http://localhost:port/patient/getDoctorInfo
```

### 请求方式

```js
POST
```

### 请求体

```js
{
  "uid", "1211",
},
```

### 返回示例

```js
* 获取成功
{
    "code": 1,
    "data": {
        "age": 23,
        "background": "10年治疗经验",
        "date": "1998-03-03",
        "department": "耳鼻喉科",
        "isDoctor": true,
        "name": "桑龙龙",
        "restNum": 10,
        "sex": "男",
        "status": 1,
        "uid": "1"
    }
}
* 获取失败
{
    "code": 0,
    "msg": "你查询的人不是医生"
}
```





## 患者完善信息

当前登录用户可以修改

### 请求 URL

```js
http://localhost:port/patient/setInfor
```

### 请求方式

```js
POST
```

### 请求体

```js
{
  "name": "用户1",//如果不修改，置为""即可
  "pass": "pass1",
  "sex": "男",
  "date": "1998-01-01",
},
```

### 返回示例

```js
* 获取成功
  {
    "code": 1,
     "msg": "success"
  }
* 获取失败
  {
    "code": 0,
    "msg": "some error information"
  }
```











## 患者登出

当前登陆用户操作，非登录用户操作会失败

### 请求 URL

```js
http://localhost:port/patient/logout
```

### 请求方式

```js
GET
```

### 请求体

```js
无
```

### 返回示例

```js
成功
{"code": 1}
失败//本身就没有登录
{"code", 0}
```










## 患者查看可预约情况/查看医生列表

### 请求 URL

```js
http://localhost:port/patient/doctorsList
```

### 请求方式

```js
GET
```

### 请求体

```js
无
```

### 返回示例

```js
* 获取成功
{
    "code": "1",
    "data": [
        {
            "background": "专治骨科",
            "date": "1998-03-03",
            "department": "骨科",
            "isDoctor": true,
            "name": "田泽远",
            "restNum": 12,
            "sex": "男",
            "status": 1,
            "uid": "0"
        },
        {
            "background": "10年治疗经验",
            "date": "1998-03-03",
            "department": "耳鼻喉科",
            "isDoctor": true,
            "name": "桑龙龙",
            "restNum": 10,
            "sex": "男",
            "status": 1,
            "uid": "1"
        },
        {
            "background": "儿科名师",
            "date": "1998-03-03",
            "department": "儿科",
            "isDoctor": true,
            "name": "贾语璇",
            "restNum": 12,
            "sex": "女",
            "status": 1,
            "uid": "2"
        }
    ]
}
```











## 患者预约挂号

### 请求 URL

```js
http://localhost:port/patient/orderDoctor

目前登录的患者/医生向某医生uid挂号，医生也可以去挂号（挂其他医生的号），但是医生如果挂自己的号，会返回错误
```

### 请求方式

```js
POST
```

### 请求体

```js
{"uid":"12"}
```

### 返回示例

```js
* 获取成功
{
    "code": 1,
    "data": {
        "doctorUid": "0",//医生id
        "orderDate": "2021-6-12 16:35:42",//预定日期
        "patientUid": "4",//患者id
        "sid": 0,//单号，唯一
        "status": 0//状态 0 已预订， 1检查中（可以忽略）, 2（已完成），3（已取消）
    }
}
* 获取失败
  {
    "code": 0,
    "msg": "uid不是医生"
  }
```













## 患者取消预约

### 请求 URL

```js
http://localhost:port/patient/cancelOrder

目前登录用户取消预约，预约的单号为sid
```

### 请求方式

```js
POST
```

### 请求体

```js
{"sid" : "23"}//取消23号单
```

### 返回示例

```js
* 获取成功
  {
    "code": 1,
  }
* 获取失败，该用户没有预约过该医生，已经取消过该预约
  {
    "code": 0,
    "msg": "出错"
  }
```













## 患者获取自己的所有预约

当前登录患者获取自己的所有预约

### 请求 URL

```js
http://localhost:port/patient/listOrders
```

### 请求方式

```js
GET
```

### 请求体

```js
无
```

### 返回示例

```js
* 获取成功
{
    "code": 1,
    "data": [
        {
            "background": "专治骨科",
            "department": "骨科",
            "doctorAge": 23,
            "doctorDate": "1998-03-03",
            "doctorName": "田泽远",
            "doctorUid": "0",
            "orderDate": "2021-6-13 16:08:04",
            "sid": 0,
            "status": 0
        }
    ]
}
* 获取失败
  {
    "code": 0,
    "msg": "用户已经注册，请更换用户名或登陆密码不正确"
  }
```

















## 医生端，获得预约该医生的所有患者

当前登录医生获取所有的预约他的患者的表单

### 请求 URL

```js
http://localhost:port/patient/listPatients
```

当前登录的用户（前提是医生），获得预约他的患者列表

### 请求方式

```js
GET
```

### 请求体

无

### 返回示例

```js
* 获取成功
{
    "code": 1,
    "data": [
        {
            "orderDate": "2021-6-13 16:11:10",
            "patientAge": 31,
            "patientDate": "1990-01-01",
            "patientName": "病人1号",
            "patientUid": "3",
            "sid": 0,
            "status": 0
        }
    ]
}
* 获取失败
  {
    "code": 0,
    "msg": "该用户不是医生"
  }
```



















## 患者完成诊断

该医生对一个预约sid进行诊断，完成诊断

### 请求 URL

```js
http://localhost:port/patient/diagnose
```

### 请求方式

```js
POST
```

### 请求体

```js
{"sid":"12"}
```

### 返回示例

```js
* 获取成功
  {
    "code": 1,
  }
* 获取失败，该用户已经被诊断过了
  {
    "code": 0,
    "msg": "出错"
  }
```

### 备注

```js
患者完成诊断，修改单号状态 status 为 2 完成
```





















## 患者每日填报

### 请求 URL

```js
http://localhost:port/patient/monitor
```

### 请求方式

```js
POST
```

### 请求体

```js
"monitoring": {
  "mid": "001",
  "user": {
    "uid": "001",
    "name": "用户1",
    "sex": "男",
    "age": 18
  },
  "date": "2021-5-20",
  "body_temperature": 36.5,
  "location": 0, // 0-中国 1-港澳台或国外
  "get_out": False, // 近 14 日是否出省
  "discomfort": False, // 是否出现乏力、干咳等不适症状
  "touch": False, // 是否接触其他具有不适症状的人群
  "risk": "心脏有点不舒服"
}
```

### 返回示例

```js
* 获取成功
  {
    "code": 1
  }
* 获取失败
  {
    "code": 0,
    "msg": "出错"
  }
```

### 备注

```js
无
```



























## 患者接收消息推送

### 请求 URL

```js
http://localhost:port/patient/pushNews
```

### 请求方式

```js
GET
```

### 请求体

```js
无
```

### 返回示例

```js
* 获取成功
  {
    "code": 1,
    "data": [
      {
        "title": "最近广州疫情反复",
        "date": "2021-6-1",
        "content": "最近广州疫情反复，请注意！！！！！！！！！！！！！",
        "from": "中国xx网",
      },
      {
        "title": "接种疫苗",
        "date": "2021-6-2",
        "content": "最近大部分人群开始接种疫苗第一针或接种第二针，未接种的抓紧时间",
        "from": "中国xx网",
      },
    ]
  }
* 获取失败
  {
    "code": 0,
    "msg": "出错"
  }
```


