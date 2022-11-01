<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm2.aspx.cs" Inherits="TP7_AMFV_G2.WebForm2" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">

        .auto-style2 {
            width: 365px;
            height: 23px;
        }
        .auto-style3 {
            width: 385px;
            height: 23px;
        }
        .auto-style7 {
            width: 312px;
            height: 23px;
        }
        .auto-style1 {
            width: 100%;
        }
        .auto-style8 {
            width: 123px;
        }
        .auto-style9 {
            width: 912px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <table class="auto-style1">
                <tr>
                    <td class="auto-style2">
                        <asp:Label ID="lblGrupo" runat="server" Text="Grupo N°2:" Font-Bold="True"></asp:Label>
                    </td>
                    <td class="auto-style3">
                        <asp:HyperLink ID="HyperLink1" runat="server" NavigateUrl="~/WebForm1.aspx">Listado de Sucursales</asp:HyperLink>
                    </td>
                    <td class="auto-style7">
                        <asp:HyperLink ID="HyperLink2" runat="server" NavigateUrl="~/WebForm2.aspx">Mostrar Sucursales Seleccionadas</asp:HyperLink>
                    </td>
                </tr>
                <tr>
                    <td class="auto-style2">
                        <asp:Label ID="Label3" runat="server" Text="•Juan Manuel Galarce &lt;/br&gt; •Ana Magalí Fernández Vilchez &lt;/br&gt; •Melanie Del Rosario Degregorio Marrero &lt;/br&gt; •Melina Carraro &lt;/br&gt; •Nicolás Gabriel Beati"></asp:Label>
                    </td>
                    <td class="auto-style3">
                        <asp:Label ID="Label1" runat="server" Font-Bold="True" Font-Size="X-Large" Text="Mostrar Sucursales Seleccionadas"></asp:Label>
                    </td>
                    <td class="auto-style7">&nbsp;</td>
                </tr>
            </table>
        </div>
        <table class="auto-style1">
            <tr>
                <td class="auto-style8">&nbsp;</td>
                <td class="auto-style9">
                    <asp:GridView ID="gw_SucSeleccionadas" runat="server">
                    </asp:GridView>
                </td>
                <td>&nbsp;</td>
            </tr>
        </table>
    </form>
</body>
</html>
