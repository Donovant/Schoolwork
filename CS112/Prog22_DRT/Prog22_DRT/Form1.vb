Public Class Form1
    Structure Number
        Dim num As Double
    End Structure
    Dim position(69) As Number
    Private Sub frmSort_Load() Handles MyBase.Load
        Dim sr As IO.StreamReader = IO.File.OpenText("numbers.txt")
        For i As Integer = 0 To 69
            position(i).num = sr.ReadLine
        Next
        sr.Close()
    End Sub
    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim sr As IO.StreamReader = IO.File.OpenText("numbers.txt")
        For n As Integer = 1 To 69
            While sr.Peek <> -1
                n = sr.ReadLine
                lstInput.Items.Add(n)
            End While
        Next
        SortData()
        ShowData()
    End Sub
    Sub ShowData()
        For i As Integer = 0 To 69
            lstOutput.Items.Add(position(i).num)
        Next
    End Sub
    Sub SortData()
        For passNum As Integer = 1 To 69
            For index As Integer = 1 To 70 - passNum
                If (position(index - 1).num < position(index).num) Then
                    SwapData(index)
                End If
            Next
        Next
    End Sub
    Sub SwapData(ByVal index As Integer)
        Dim temp As Number
        temp = position(index - 1)
        position(index - 1) = position(index)
        position(index) = temp
    End Sub
End Class