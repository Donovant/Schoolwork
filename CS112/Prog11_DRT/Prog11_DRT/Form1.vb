Public Class txtLoan

    Private Sub btnCalc_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnCalc.Click
        Dim payment, interest, duration, amount, totalInterest As String
        interest = txtInterest.Text
        interest = interest / 12
        interest = interest / 100
        duration = txtDuration.Text
        amount = txtAmount.Text
        payment = amount * interest / (1 - (1 + interest) ^ (-duration))
        totalInterest = duration * payment - amount
        txtOutput.Text = "Monthly payment of " & (FormatCurrency(payment)) & " and total interest of " & (FormatCurrency(totalInterest))
    End Sub
End Class
