<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm3b.aspx.cs" Inherits="TP4_AMFV.WebForm3b" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:Label ID="Label1" runat="server" Font-Bold="True" Font-Size="X-Large" Text="Listado de Libros"></asp:Label>
            <br />
            <br />
            <asp:GridView ID="gwLibros" runat="server">
            </asp:GridView>
            <br />
            <br />
            <asp:LinkButton ID="LinkButton1" runat="server" OnClick="LinkButton1_Click">Consultar otro tema</asp:LinkButton>
        </div>
    </form>
</body>
</html>
