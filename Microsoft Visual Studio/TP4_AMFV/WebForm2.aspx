<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm2.aspx.cs" Inherits="TP4_AMFV.WebForm2" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">
        .auto-style1 {
            width: 100%;
        }
        .auto-style3 {
            width: 182px;
        }
        .auto-style4 {
            width: 136px;
        }
        .auto-style5 {
            width: 136px;
            height: 23px;
        }
        .auto-style6 {
            width: 182px;
            height: 23px;
        }
        .auto-style7 {
            height: 23px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <table class="auto-style1">
                <tr>
                    <td class="auto-style4">
                        <asp:Label ID="Label1" runat="server" Text="ID Producto:"></asp:Label>
                    </td>
                    <td class="auto-style3">
                        <asp:DropDownList ID="ddlProducto" runat="server">
                            <asp:ListItem Value="=">Igual a</asp:ListItem>
                            <asp:ListItem Value="&lt;">menor que</asp:ListItem>
                            <asp:ListItem Value="&gt;">mayor a </asp:ListItem>
                        </asp:DropDownList>
                    </td>
                    <td>
                        <asp:TextBox ID="txtIdProd" runat="server"></asp:TextBox>
                    </td>
                    <td>&nbsp;</td>
                </tr>
                <tr>
                    <td class="auto-style4">
                        <asp:Label ID="Label2" runat="server" Text="ID Categoría:"></asp:Label>
                    </td>
                    <td class="auto-style3">
                        <asp:DropDownList ID="ddlCategoria" runat="server">
                            <asp:ListItem Value="=">Igual a </asp:ListItem>
                            <asp:ListItem Value="&lt;">menor a</asp:ListItem>
                            <asp:ListItem Value="&gt;">mayor a</asp:ListItem>
                        </asp:DropDownList>
                    </td>
                    <td>
                        <asp:TextBox ID="txtIdCat" runat="server"></asp:TextBox>
                    </td>
                    <td>&nbsp;</td>
                </tr>
                <tr>
                    <td class="auto-style5"></td>
                    <td class="auto-style6">
                        <asp:Button ID="btnFiltrar" runat="server" Text="Filtrar" OnClick="btnFiltrar_Click" />
                    </td>
                    <td class="auto-style7">
                        <asp:Button ID="btnQuitFil" runat="server" Text="Quitar Filtro" OnClick="btnQuitFil_Click" />
                    </td>
                    <td class="auto-style7"></td>
                </tr>
            </table>
        </div>
        <asp:GridView ID="gwTabla" runat="server">
        </asp:GridView>
    </form>
</body>
</html>
