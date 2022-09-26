<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm3.aspx.cs" Inherits="TP4_AMFV.WebForm3" %>

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
            width: 195px;
            height: 59px;
        }
        .auto-style3 {
            width: 396px;
            height: 59px;
        }
        .auto-style4 {
            width: 195px;
            height: 66px;
        }
        .auto-style5 {
            width: 396px;
            height: 66px;
        }
        .auto-style6 {
            height: 66px;
        }
        .auto-style7 {
            height: 59px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <table class="auto-style1">
                <tr>
                    <td class="auto-style4">
                        <asp:Label ID="Label1" runat="server" Text="Seleccionar un tema:"></asp:Label>
                    </td>
                    <td class="auto-style5">
                        <asp:DropDownList ID="ddlTemas" runat="server" AppendDataBoundItems="True" AutoPostBack="True">
                            <asp:ListItem>--Seleccione un tema--</asp:ListItem>
                        </asp:DropDownList>
                    </td>
                    <td class="auto-style6"></td>
                </tr>
                <tr>
                    <td class="auto-style2">
                        <asp:LinkButton ID="LinkButton1" runat="server" OnClick="LinkButton1_Click">Ver Libros</asp:LinkButton>
                    </td>
                    <td class="auto-style3"></td>
                    <td class="auto-style7"></td>
                </tr>
            </table>
        </div>
    </form>
</body>
</html>
