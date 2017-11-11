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
        Me.Cycling = New System.Windows.Forms.TextBox
        Me.Running = New System.Windows.Forms.TextBox
        Me.Swimming = New System.Windows.Forms.TextBox
        Me.Button1 = New System.Windows.Forms.Button
        Me.Label1 = New System.Windows.Forms.Label
        Me.Label2 = New System.Windows.Forms.Label
        Me.Label3 = New System.Windows.Forms.Label
        Me.Output = New System.Windows.Forms.TextBox
        Me.SuspendLayout()
        '
        'Cycling
        '
        Me.Cycling.Location = New System.Drawing.Point(152, 23)
        Me.Cycling.Name = "Cycling"
        Me.Cycling.Size = New System.Drawing.Size(69, 20)
        Me.Cycling.TabIndex = 0
        '
        'Running
        '
        Me.Running.Location = New System.Drawing.Point(152, 59)
        Me.Running.Name = "Running"
        Me.Running.Size = New System.Drawing.Size(69, 20)
        Me.Running.TabIndex = 1
        '
        'Swimming
        '
        Me.Swimming.Location = New System.Drawing.Point(152, 95)
        Me.Swimming.Name = "Swimming"
        Me.Swimming.Size = New System.Drawing.Size(69, 20)
        Me.Swimming.TabIndex = 2
        '
        'Button1
        '
        Me.Button1.Location = New System.Drawing.Point(49, 164)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(127, 23)
        Me.Button1.TabIndex = 3
        Me.Button1.Text = "Compute Weight Loss"
        Me.Button1.UseVisualStyleBackColor = True
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(8, 25)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(124, 13)
        Me.Label1.TabIndex = 4
        Me.Label1.Text = "Number of hours cycling:"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(8, 60)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(126, 13)
        Me.Label2.TabIndex = 5
        Me.Label2.Text = "Number of hours running:"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(8, 95)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(138, 13)
        Me.Label3.TabIndex = 6
        Me.Label3.Text = "Number of hours Swimming:"
        '
        'Output
        '
        Me.Output.Location = New System.Drawing.Point(49, 216)
        Me.Output.Name = "Output"
        Me.Output.ReadOnly = True
        Me.Output.Size = New System.Drawing.Size(127, 20)
        Me.Output.TabIndex = 7
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(227, 262)
        Me.Controls.Add(Me.Output)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.Button1)
        Me.Controls.Add(Me.Swimming)
        Me.Controls.Add(Me.Running)
        Me.Controls.Add(Me.Cycling)
        Me.Name = "Form1"
        Me.Text = "Triathlon"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents Cycling As System.Windows.Forms.TextBox
    Friend WithEvents Running As System.Windows.Forms.TextBox
    Friend WithEvents Swimming As System.Windows.Forms.TextBox
    Friend WithEvents Button1 As System.Windows.Forms.Button
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents Output As System.Windows.Forms.TextBox

End Class
