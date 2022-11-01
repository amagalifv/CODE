<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Ejercicio2.aspx.cs" Inherits="TP6_AMFV.Ejercicio2" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:Label ID="Label1" runat="server" Font-Bold="True" Font-Size="XX-Large" Text="Inicio"></asp:Label>
            <br />
            <br />
            <br />
            <asp:HyperLink ID="HyperLink1" runat="server" NavigateUrl="~/Ejercicio2a.aspx">Seleccionar Productos</asp:HyperLink>
            <br />
            <br />
            <asp:LinkButton ID="lb_EliminarSession" runat="server" OnClick="lb_EliminarSession_Click">Eliminar Productos Seleccionados</asp:LinkButton>
            <br />
            <br />
            <asp:HyperLink ID="HyperLink2" runat="server" NavigateUrl="~/Ejercicio2c.aspx">Mostrar Productos</asp:HyperLink>
            <br />
            <br />
            <br />
            <br />
            <asp:HyperLink ID="HyperLink4" runat="server" NavigateUrl="~/home.aspx">Ir a Principal</asp:HyperLink>
        </div>
    </form>
</body>
</html>
