<%@page isELIgnored="false"%>
<html>
<body>
<h2>Hello World!</h2>

<%--%{pageContext.request.contextPath}是当前项目的原地址，需要引入javax.servlet.jsp-api这个包--%>
<form action="${pageContext.request.contextPath}/login" method="get">
    用户名: <input type="text" name = "username"> <br>
    密码: <input type="password" name = "password"> <br>
    <input type="submit">
</form>
</body>
</html>
