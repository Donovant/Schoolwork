Public Class Form1
    Dim List(49) As Data
    Private Sub ListBox1_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles lstInput.SelectedIndexChanged

    End Sub
    Structure Data
        Dim State As String
        Dim Abbrv As String
        Dim Year As String
        Dim Area As String
        Dim Pop As String

    End Structure
    Private Sub frmData_Load() Handles MyBase.Load
        Dim line, Data() As String
        Dim sr As IO.StreamReader = IO.File.OpenText("csvUSSTATES.txt")
        Dim Count As Integer = 0
        Do While (sr.Peek <> -1)
            line = sr.ReadLine
            lstInput.Items.Add(line)
            Data = line.Split(","c)
            List(Count).State = Data(0)
            List(Count).Abbrv = Data(1)
            List(Count).Year = Data(2)
            List(Count).Area = Data(3)
            List(Count).Pop = Data(4)
            Count += 1
        Loop
        sr.Close()
    End Sub
    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        DataSort()
        DataShow()

    End Sub
    Sub DataShow()
        Dim sw As IO.StreamWriter = IO.File.CreateText("Output.txt")
        lstOutput.Items.Clear()
        Dim fmtStr As String = "{0, -20}{1, -10}{2, -12}{3, -10}{4, 10}"
        lstOutput.Items.Add(String.Format(fmtStr, "State", "Abbrv", "Year", "Area", "Pop"))
        For i As Integer = 0 To 49
            lstOutput.Items.Add(String.Format(fmtStr, List(i).State, List(i).Abbrv, List(i).Year, List(i).Area, List(i).Pop))
            sw.WriteLine(String.Format(fmtStr, List(i).State, List(i).Abbrv, List(i).Year, List(i).Area, List(i).Pop))
        Next
        sw.Close()
    End Sub
    Sub DataSort()
        For passNum As Integer = 1 To 49
            For index As Integer = 1 To 50 - passNum
                If (List(index - 1).Abbrv > List(index).Abbrv) Then
                    DataSwap(index)
                End If
            Next
        Next
    End Sub
    Sub DataSwap(ByVal index As Integer)
        Dim temp As Data
        temp = List(index - 1)
        List(index - 1) = List(index)
        List(index) = temp
    End Sub
End Class