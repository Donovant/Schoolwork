Public Class Form1

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim coefficient, max As Integer
        Dim number As Integer = 0
        For num As Integer = 1 To 10000
            For divisor As Integer = 1 To num - 1
                If (num Mod divisor = 0) Then
                    number += divisor
                End If
            Next
            If number = num Then
                lstOutput.Items.Add(number)
            End If
            number = 0
        Next
    End Sub
End Class
