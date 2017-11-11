Public Class Form1

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim num1 As Double
        Dim num2 As Double
        Dim answer As Double
        num1 = CDbl(first.Text)
        num2 = CDbl(second.Text)
        answer = num1 + num2
        output.Text = num1 & " + " & num2 & " = " & answer

    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        Dim num1 As Double
        Dim num2 As Double
        Dim answer As Double
        num1 = CDbl(first.Text)
        num2 = CDbl(second.Text)
        answer = num1 - num2
        output.Text = num1 & " - " & num2 & " = " & answer
    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        Dim num1 As Double
        Dim num2 As Double
        Dim answer As Double
        num1 = CDbl(first.Text)
        num2 = CDbl(second.Text)
        answer = num1 * num2
        output.Text = num1 & " * " & num2 & " = " & answer
    End Sub

    Private Sub Button4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click
        Dim num1 As Double
        Dim num2 As Double
        Dim answer As Double
        num1 = CDbl(first.Text)
        num2 = CDbl(second.Text)
        answer = num1 / num2
        output.Text = num1 & " ÷ " & num2 & " = " & answer
    End Sub

    Private Sub Button5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button5.Click
        Dim num1 As Double
        Dim num2 As Double
        Dim answer As Double
        num1 = CDbl(first.Text)
        num2 = CDbl(second.Text)
        answer = num1 Mod num2
        output.Text = num1 & " Mod " & num2 & " = " & answer
    End Sub

    Private Sub Button6_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button6.Click
        first.Clear()
        second.Clear()
        output.Clear()
    End Sub
End Class
