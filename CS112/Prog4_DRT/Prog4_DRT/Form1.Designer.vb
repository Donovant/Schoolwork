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
        Me.Label1 = New System.Windows.Forms.Label
        Me.Label2 = New System.Windows.Forms.Label
        Me.Label3 = New System.Windows.Forms.Label
        Me.Team = New System.Windows.Forms.TextBox
        Me.Won = New System.Windows.Forms.TextBox
        Me.Lost = New System.Windows.Forms.TextBox
        Me.Output = New System.Windows.Forms.TextBox
        Me.Button1 = New System.Windows.Forms.Button
        Me.SuspendLayout()
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(68, 27)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(37, 13)
        Me.Label1.TabIndex = 0
        Me.Label1.Text = "Team:"
        Me.Label1.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(36, 67)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(69, 13)
        Me.Label2.TabIndex = 1
        Me.Label2.Text = "Games Won:"
        Me.Label2.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(39, 111)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(66, 13)
        Me.Label3.TabIndex = 2
        Me.Label3.Text = "Games Lost:"
        Me.Label3.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Team
        '
        Me.Team.Location = New System.Drawing.Point(122, 27)
        Me.Team.Name = "Team"
        Me.Team.Size = New System.Drawing.Size(100, 20)
        Me.Team.TabIndex = 3
        '
        'Won
        '
        Me.Won.Location = New System.Drawing.Point(122, 67)
        Me.Won.Name = "Won"
        Me.Won.Size = New System.Drawing.Size(100, 20)
        Me.Won.TabIndex = 4
        '
        'Lost
        '
        Me.Lost.Location = New System.Drawing.Point(122, 111)
        Me.Lost.Name = "Lost"
        Me.Lost.Size = New System.Drawing.Size(100, 20)
        Me.Lost.TabIndex = 5
        '
        'Output
        '
        Me.Output.Location = New System.Drawing.Point(27, 183)
        Me.Output.Name = "Output"
        Me.Output.ReadOnly = True
        Me.Output.Size = New System.Drawing.Size(220, 20)
        Me.Output.TabIndex = 6
        '
        'Button1
        '
        Me.Button1.Location = New System.Drawing.Point(71, 154)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(128, 23)
        Me.Button1.TabIndex = 7
        Me.Button1.Text = "Compute Percentage"
        Me.Button1.UseVisualStyleBackColor = True
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(273, 221)
        Me.Controls.Add(Me.Button1)
        Me.Controls.Add(Me.Output)
        Me.Controls.Add(Me.Lost)
        Me.Controls.Add(Me.Won)
        Me.Controls.Add(Me.Team)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Label1)
        Me.Name = "Form1"
        Me.Text = "Baseball"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents Team As System.Windows.Forms.TextBox
    Friend WithEvents Won As System.Windows.Forms.TextBox
    Friend WithEvents Lost As System.Windows.Forms.TextBox
    Friend WithEvents Output As System.Windows.Forms.TextBox
    Friend WithEvents Button1 As System.Windows.Forms.Button

End Class
