<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Ejercicio5.aspx.cs" Inherits="TP2.Ejercicio5" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">
        .auto-style1 {
            width: 100%;
        }
        .auto-style2 {
            width: 306px;
        }
        .auto-style3 {
            width: 182px;
        }
        .auto-style4 {
            width: 1px;
        }
        .auto-style5 {
            width: 161px;
        }
        .auto-style6 {
            width: 161px;
            height: 17px;
        }
        .auto-style7 {
            width: 306px;
            height: 17px;
        }
        .auto-style8 {
            width: 1px;
            height: 17px;
        }
        .auto-style9 {
            width: 182px;
            height: 17px;
        }
        .auto-style10 {
            height: 17px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:Label ID="Label1" runat="server" Font-Bold="True" Font-Size="Larger" Text="Elija su configuracion"></asp:Label>
            <br />
            <br />
            <table class="auto-style1">
                <tr>
                    <td class="auto-style5">&nbsp;</td>
                    <td class="auto-style2">&nbsp;<b>Seleccione la cantidad de memoria</b></td>
                    <td class="auto-style4">&nbsp;</td>
                    <td class="auto-style3"><b>Seleccione accesorios</b></td>
                    <td>&nbsp;</td>
                    <td>&nbsp;</td>
                    <td>&nbsp;</td>
                    <td>&nbsp;</td>
                    <td>&nbsp;</td>
                </tr>
                <tr>
                    <td class="auto-style5">&nbsp;</td>
                    <td class="auto-style2">&nbsp;<asp:DropDownList ID="ddlMemoria" runat="server">
                        <asp:ListItem Value="200">2GB</asp:ListItem>
                        <asp:ListItem Value="375">4GB</asp:ListItem>
                        <asp:ListItem Value="500">6GB</asp:ListItem>
                        </asp:DropDownList>
                    </td>
                    <td class="auto-style4">&nbsp;</td>
                    <td class="auto-style3">
                        <asp:CheckBoxList ID="clbAccesorios" runat="server" Font-Size="Medium">
                            <asp:ListItem Value="2000.50">Monitor LCD</asp:ListItem>
                            <asp:ListItem Value="550.50">HD 500GB</asp:ListItem>
                            <asp:ListItem Value="1200">Grabador DVD</asp:ListItem>
                        </asp:CheckBoxList>
                    </td>
                    <td>&nbsp;</td>
                    <td>&nbsp;</td>
                    <td>&nbsp;</td>
                    <td>&nbsp;</td>
                    <td>&nbsp;</td>
                </tr>
                <tr>
                    <td class="auto-style5">&nbsp;</td>
                    <td class="auto-style2">&nbsp;</td>
                    <td class="auto-style4">&nbsp;</td>
                    <td class="auto-style3">&nbsp;</td>
                    <td>&nbsp;</td>
                    <td>&nbsp;</td>
                    <td>&nbsp;</td>
                    <td>&nbsp;</td>
                    <td>&nbsp;</td>
                </tr>
                <tr>
                    <td class="auto-style5">&nbsp;</td>
                    <td class="auto-style2">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
                        <asp:Button ID="btnCalcularPrecio" runat="server" OnClick="btnCalcularPrecio_Click" Text="Calcular precio" />
                        &nbsp;</td>
                    <td class="auto-style4">&nbsp;</td>
                    <td class="auto-style3">&nbsp;</td>
                    <td>&nbsp;</td>
                    <td>&nbsp;</td>
                    <td>&nbsp;</td>
                    <td>&nbsp;</td>
                    <td>&nbsp;</td>
                </tr>
                <tr>
                    <td class="auto-style5">&nbsp;</td>
                    <td class="auto-style2">&nbsp;</td>
                    <td class="auto-style4">&nbsp;</td>
                    <td class="auto-style3">&nbsp;</td>
                    <td>&nbsp;</td>
                    <td>&nbsp;</td>
                    <td>&nbsp;</td>
                    <td>&nbsp;</td>
                    <td>&nbsp;</td>
                </tr>
                </table>
                        <asp:Label ID="lblPrecioFinal" runat="server" Font-Bold="True" Font-Size="Larger"></asp:Label>
            <br />
            <br />
        </div>
    </form>
</body>
</html>
