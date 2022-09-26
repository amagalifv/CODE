<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Ejercicio1.aspx.cs" Inherits="TP2.FormPrincipal" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <br />
            Ingrese nombre producto:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            <asp:TextBox ID="txtNombre1" runat="server"></asp:TextBox>
&nbsp;Cantidad:&nbsp;&nbsp;&nbsp;
            <asp:TextBox ID="txtCantidad1" runat="server"></asp:TextBox>
&nbsp;&nbsp;&nbsp;&nbsp;
            <br />
            Ingrese nombre producto:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            <asp:TextBox ID="txtNombre2" runat="server"></asp:TextBox>
&nbsp;Cantidad:&nbsp;&nbsp;&nbsp;
            <asp:TextBox ID="txtCantidad2" runat="server"></asp:TextBox>
&nbsp;
        </div>
        <p>
            <asp:Button ID="btnGenerarTabla" runat="server" OnClick="btnGenerarTabla_Click" Text="Generar Tabla" />
        </p>
        <p>
            <asp:Label ID="lblTabla" runat="server"></asp:Label>
        </p>
    </form>
</body>
</html>
