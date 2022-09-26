<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm3.aspx.cs" Inherits="TP2.WebForm3" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            &nbsp;&nbsp;&nbsp;
            <asp:LinkButton ID="linkBtnRojo" runat="server" OnClick="linkBtnRojo_Click">Rojo</asp:LinkButton>
            <br />
            &nbsp;&nbsp;&nbsp;
            <asp:LinkButton ID="linkBtnVerde" runat="server" OnClick="linkBtnVerde_Click">Verde</asp:LinkButton>
            <br />
            &nbsp;&nbsp;&nbsp;
            <asp:LinkButton ID="linkBtnAzul" runat="server" OnClick="linkBtnAzul_Click">Azul</asp:LinkButton>
            <br />
            <br />
            &nbsp;&nbsp;
            <asp:Label ID="lblTexto" runat="server" Text="Texto Coloreado"></asp:Label>
        </div>
    </form>
</body>
</html>
