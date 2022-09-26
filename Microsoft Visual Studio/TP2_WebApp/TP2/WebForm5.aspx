<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm5.aspx.cs" Inherits="TP2.WebForm5" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">
        .auto-style1 {
            width: 100%;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:Label ID="Label1" runat="server" Font-Bold="True" Font-Size="X-Large" Text="Elija su configuración:"></asp:Label>
            <br />
            <table class="auto-style1">
                <tr>
                    <td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;</td>
                    <td>
            <asp:Label ID="Label2" runat="server" Font-Bold="True" Font-Size="Large" Text="Seleccione cantidad de memoria:"></asp:Label>
                    </td>
                    <td>
            <asp:Label ID="Label3" runat="server" Font-Bold="True" Font-Size="Large" Text="Seleccione accesorios:"></asp:Label>
                    </td>
                    <td>&nbsp;</td>
                </tr>
                <tr>
                    <td>&nbsp;</td>
                    <td>
            <asp:DropDownList ID="ddlMemoria" runat="server">
                <asp:ListItem>2 GB</asp:ListItem>
                <asp:ListItem>4 GB</asp:ListItem>
                <asp:ListItem>6 GB</asp:ListItem>
            </asp:DropDownList>
                    </td>
                    <td>
                <asp:CheckBoxList ID="cblAccesorios" runat="server">
                    <asp:ListItem Selected="True">Monitor LCD</asp:ListItem>
                    <asp:ListItem>HD 500GB</asp:ListItem>
                    <asp:ListItem>Grabador DVD</asp:ListItem>
                </asp:CheckBoxList>
                    </td>
                    <td>&nbsp;</td>
                </tr>
                <tr>
                    <td>&nbsp;</td>
                    <td>
            <asp:Button ID="btnCalcPrecio" runat="server" Text="Calcular Precio" OnClick="btnCalcPrecio_Click" />
                    </td>
                    <td>
                        <br />
                    </td>
                    <td>&nbsp;</td>
                </tr>
            </table>
            &nbsp;&nbsp;<br />
            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
            <asp:Label ID="lblPrecioFinal" runat="server" Font-Bold="True" Font-Size="Larger"></asp:Label>
        </div>
    </form>
</body>
</html>
