Public Class Form1


    Private Sub TextBox1_GotFocus(ByVal sender As Object, ByVal e As System.EventArgs) Handles TextBoxOne.GotFocus
        TextBoxOne.ForeColor = Color.Red

    End Sub

    Private Sub TextBox2_GotFocus(ByVal sender As Object, ByVal e As System.EventArgs) Handles TextBoxTwo.GotFocus
        TextBoxTwo.ForeColor = Color.Red

    End Sub

    Private Sub TextBox3_GotFocus(ByVal sender As Object, ByVal e As System.EventArgs) Handles TextBoxThree.GotFocus
        TextBoxThree.ForeColor = Color.Red

    End Sub

    Private Sub TextBox1_LostFocus(ByVal sender As Object, ByVal e As System.EventArgs) Handles TextBoxOne.LostFocus
        TextBoxOne.ForeColor = Color.Black

    End Sub

    Private Sub TextBox2_LostFocus(ByVal sender As Object, ByVal e As System.EventArgs) Handles TextBoxTwo.LostFocus
        TextBoxTwo.ForeColor = Color.Black

    End Sub

    Private Sub TextBox3_LostFocus(ByVal sender As Object, ByVal e As System.EventArgs) Handles TextBoxThree.LostFocus
        TextBoxThree.ForeColor = Color.Black

    End Sub

    Private Sub LeftButton_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles LeftButton.Click
        TextBoxOne.TextAlign = HorizontalAlignment.Left
        TextBoxTwo.TextAlign = HorizontalAlignment.Left
        TextBoxThree.TextAlign = HorizontalAlignment.Left

    End Sub

    Private Sub RightButton_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles RightButton.Click
        TextBoxOne.TextAlign = HorizontalAlignment.Right
        TextBoxTwo.TextAlign = HorizontalAlignment.Right
        TextBoxThree.TextAlign = HorizontalAlignment.Right
    End Sub
End Class
