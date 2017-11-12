Public Class Form1

    Private Sub TextBox1_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles input.TextChanged

    End Sub

    Private Sub calc_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles calc.Click
        Dim tax, income As String
        tax = output.Text
        income = CDbl(input.Text)
        If ((income > 0) And (income <= 7825)) Then
            output.Text = CDbl(income * 0.1)
        ElseIf ((income > 7825) And (income <= 31850)) Then
            output.Text = CDbl(((income - 7825) * 0.15) + 782.5)
        ElseIf ((income > 31850) And (income <= 77100)) Then
            output.Text = CDbl(((income - 31850) * 0.25) + 4386.25)
        ElseIf ((income > 77100) And (income <= 160850)) Then
            output.Text = CDbl(((income - 77100) * 0.28) + 15698.75)
        ElseIf ((income > 160850) And (income <= 349700)) Then
            output.Text = CDbl(((income - 160850) * 0.33) + 39148.75)
        ElseIf (income > 349700) Then
            output.Text = CDbl(((income - 101469.25) * 0.35) + 101469.25)
        End If

    End Sub
End Class
