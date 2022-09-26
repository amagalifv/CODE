<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="TP2.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    </head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:Label ID="lblPro1" runat="server" Text="Ingrese nombre producto:"></asp:Label>
            &nbsp;&nbsp;&nbsp;&nbsp;
            <asp:TextBox ID="txtProd1" runat="server"></asp:TextBox>
            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            <asp:Label ID="lblCantProd1" runat="server" Text="Cantidad:"></asp:Label>
            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            <asp:TextBox ID="txtCantProd1" runat="server"></asp:TextBox>
            <br />
        </div>
        <br />
        <asp:Label ID="lblProd2" runat="server" Text="Ingrese nombre producto:"></asp:Label>
        &nbsp;&nbsp;&nbsp;&nbsp;
        <asp:TextBox ID="txtProd2" runat="server"></asp:TextBox>
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <asp:Label ID="lblCantProd2" runat="server" Text="Cantidad:"></asp:Label>
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <asp:TextBox ID="txtCantProd2" runat="server"></asp:TextBox>
        <br />
        <br />
        <asp:Button ID="btnGenTabla" runat="server" Text="Generar Tabla" OnClick="btnGenTabla_Click" />
        <br />
        <br />
        <asp:Label ID="lblTabla" runat="server"></asp:Label>
        <br />
    </form>
</body>
</html>
