Public Class Form1

    Private Sub GreenBox_GotFocus(ByVal sender As Object, ByVal e As System.EventArgs) Handles GreenBox.GotFocus
        GreenBox.BackColor = Color.Green
    End Sub

    Private Sub GreenBox_LostFocus(ByVal sender As Object, ByVal e As System.EventArgs) Handles GreenBox.LostFocus
        GreenBox.BackColor = Color.DarkGray
    End Sub

    Private Sub YellowBox_GotFocus(ByVal sender As Object, ByVal e As System.EventArgs) Handles YellowBox.GotFocus
        YellowBox.BackColor = Color.Yellow
    End Sub

    Private Sub YellowBox_LostFocus(ByVal sender As Object, ByVal e As System.EventArgs) Handles YellowBox.LostFocus
        YellowBox.BackColor = Color.DarkGray
    End Sub

    Private Sub RedBox_GotFocus(ByVal sender As Object, ByVal e As System.EventArgs) Handles RedBox.GotFocus
        RedBox.BackColor = Color.Red
    End Sub

    Private Sub RedBox_LostFocus(ByVal sender As Object, ByVal e As System.EventArgs) Handles RedBox.LostFocus
        RedBox.BackColor = Color.DarkGray
    End Sub
End Class
