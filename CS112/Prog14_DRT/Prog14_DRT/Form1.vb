Public Class Form1
    Function CalculateTotal(ByVal val1 As Double, ByVal val2 As Double)
        Dim total As Double
        total = val1 * val2
        Return total
    End Function

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles computeBtn.Click
        Dim fmtStr As String = "{0, -15}{1, -10}{2, -10:C2}"
        lstOutput.Items.Add(String.Format(fmtStr, "Item", "Quantity", "Price"))
        RequestInput()
    End Sub
    Sub RequestInput()
        Dim pizzaPrice As Double = 1.75
        Dim friesPrice As Double = 2.0
        Dim drinkPrice As Double = 1.25
        Dim pizza, fries, drink, grandTotal As Double
        pizza = pizzaTxt.Text
        fries = friesTxt.Text
        drink = drinkTxt.Text
        Output("Pizza Slices", pizza, pizzaPrice)
        grandTotal += CalculateTotal(pizza, pizzaPrice)
        Output("French Fries", fries, friesPrice)
        grandTotal += CalculateTotal(fries, friesPrice)
        Output("Soft Drinks", drink, drinkPrice)
        grandTotal += CalculateTotal(drink, drinkPrice)
        Output(grandTotal)

    End Sub
    Sub Output(ByVal name As String, ByVal val3 As Double, ByVal val4 As Double)
        Dim fmtStr As String = "{0, -15}{1, -10}{2, -10:C2}"
        lstOutput.Items.Add(String.Format(fmtStr, name, val3, (CalculateTotal(val3, val4))))

    End Sub
    Sub Output(ByVal val3 As Double)
        Dim fmtStr As String = "{0, -15}{1, -10}{2, -10:C2}"
        lstOutput.Items.Add(String.Format(fmtStr, "Total", "", val3))

    End Sub
End Class
