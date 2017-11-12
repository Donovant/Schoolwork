<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.info = New System.Windows.Forms.ListBox
        Me.Button1 = New System.Windows.Forms.Button
        Me.grade = New System.Windows.Forms.TextBox
        Me.letter = New System.Windows.Forms.Label
        Me.SuspendLayout()
        '
        'info
        '
        Me.info.Font = New System.Drawing.Font("Courier New", 9.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.info.FormattingEnabled = True
        Me.info.ItemHeight = 15
        Me.info.Location = New System.Drawing.Point(118, 12)
        Me.info.Name = "info"
        Me.info.Size = New System.Drawing.Size(320, 379)
        Me.info.TabIndex = 1
        '
        'Button1
        '
        Me.Button1.Location = New System.Drawing.Point(20, 12)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(75, 23)
        Me.Button1.TabIndex = 2
        Me.Button1.Text = "Button1"
        Me.Button1.UseVisualStyleBackColor = True
        '
        'grade
        '
        Me.grade.Font = New System.Drawing.Font("Courier New", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.grade.Location = New System.Drawing.Point(20, 242)
        Me.grade.Name = "grade"
        Me.grade.ReadOnly = True
        Me.grade.Size = New System.Drawing.Size(75, 20)
        Me.grade.TabIndex = 4
        Me.grade.TabStop = False
        '
        'letter
        '
        Me.letter.AutoSize = True
        Me.letter.Location = New System.Drawing.Point(20, 226)
        Me.letter.Name = "letter"
        Me.letter.Size = New System.Drawing.Size(66, 13)
        Me.letter.TabIndex = 5
        Me.letter.Text = "Letter Grade"
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(454, 403)
        Me.Controls.Add(Me.letter)
        Me.Controls.Add(Me.grade)
        Me.Controls.Add(Me.Button1)
        Me.Controls.Add(Me.info)
        Me.Name = "Form1"
        Me.Text = "Visual Basic Grades"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents info As System.Windows.Forms.ListBox
    Friend WithEvents Button1 As System.Windows.Forms.Button
    Friend WithEvents grade As System.Windows.Forms.TextBox
    Friend WithEvents letter As System.Windows.Forms.Label

End Class
