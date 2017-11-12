Public Class Form1

    Private Sub humor_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles humor.Click
        Dim num As Double
        Dim phrase As String
        num = input.Text
        If input.Text = "1" Then
            output.Text = "Some of the world's greatest feats were accomplished by people not smart enough to know they were impossible."
        ElseIf input.Text = "2" Then
            output.Text = "Women will never be as successful as men because they have no wives to advise them."
        ElseIf input.Text = "3" Then
            output.Text = "If at first you don't succeed, destroy all evidence that you tried."
        Else : input.Clear()
        End If
    End Sub

    Private Sub insult_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles insult.Click
        Dim num As Double
        Dim phrase As String
        num = input.Text
        If input.Text = "1" Then
            output.Text = "If brains were taxed, you’d get a rebate."
        ElseIf input.Text = "2" Then
            output.Text = "You are prime candidate for natural deselection."
        ElseIf input.Text = "3" Then
            output.Text = "Shouldn't you have a license for being that ugly?"
        Else : input.Clear()
        End If

    End Sub
End Class
