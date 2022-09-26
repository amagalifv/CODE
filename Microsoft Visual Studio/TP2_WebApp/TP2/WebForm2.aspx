<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm2.aspx.cs" Inherits="TP2.WebForm2" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            &nbsp;&nbsp;&nbsp;&nbsp;
            <asp:Label ID="lblNombre" runat="server" Text="Nombre:"></asp:Label>
            &nbsp;&nbsp;
            <asp:TextBox ID="txtNombre" runat="server"></asp:TextBox>
            <br />
            <br />
            &nbsp;&nbsp;&nbsp;&nbsp;
            <asp:Label ID="lblApellido" runat="server" Text="Apellido:"></asp:Label>
            &nbsp;&nbsp;
            <asp:TextBox ID="txtApellido" runat="server"></asp:TextBox>
            <br />
            <br />
            &nbsp;&nbsp;&nbsp;&nbsp;
            <asp:Label ID="lblCiudad" runat="server" Text="Ciudad:"></asp:Label>
            &nbsp;&nbsp;
            <asp:DropDownList ID="ddlCiudad" runat="server">
                <asp:ListItem>Gral Pacheco</asp:ListItem>
                <asp:ListItem>Boedo</asp:ListItem>
                <asp:ListItem>San Miguel</asp:ListItem>
            </asp:DropDownList>
            <br />
            <br />
            &nbsp;&nbsp;&nbsp;&nbsp;
            <asp:Label ID="lblTemas" runat="server" Text="Temas:"></asp:Label>
            <br />
                <div style="margin:20px">
                    <asp:CheckBoxList ID="cblTemas" runat="server" Width="300px">
                        <asp:ListItem Selected="True">Ciencias</asp:ListItem>
                        <asp:ListItem>Literatura</asp:ListItem>
                        <asp:ListItem>Historia</asp:ListItem>
                    </asp:CheckBoxList>
                </div>
                <div>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                    <asp:Button ID="btnVerResumen" runat="server" Text="Ver Resumen" OnClick="btnVerResumen_Click" />
                </div>
            <br />
            <br />
        </div>
    </form>
</body>
</html>
