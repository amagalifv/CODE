<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Ejercicio3.aspx.cs" Inherits="TP2.Ejercicio3" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:LinkButton ID="lbtnRojo" runat="server" OnClick="lbtnRojo_Click">Rojo</asp:LinkButton>
            <br />
            <asp:LinkButton ID="lbtnAzul" runat="server" OnClick="lbtnAzul_Click">Azul</asp:LinkButton>
            <br />
            <asp:LinkButton ID="lbtnVerde" runat="server" OnClick="lbtnVerde_Click">Verde</asp:LinkButton>
            <br />
            <br />
            <br />
            <asp:Label ID="lblTexto" runat="server" ForeColor="Black" Text="Texto coloreado"></asp:Label>
        </div>
    </form>
</body>
</html>
