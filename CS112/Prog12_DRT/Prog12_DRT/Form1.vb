Public Class Form1
    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim amount, job, tip, total As String
        job = txtJob.Text
        amount = txtAmount.Text
        tip = txtTip.Text / 100
        total = FormatCurrency(amount * tip)
        amount = FormatCurrency(amount)
        DisplayOutput(job, total)

    End Sub
    Sub DisplayOutput(ByVal job As String, ByVal total As String)
        txtOutput.Text = "Tip the " & job & " " & total
    End Sub
End Class
