"""create_db

Revision ID: eb2b4ed7a0d7
Revises: 
Create Date: 2026-09-04 16:25:47.373864

"""
from typing import Sequence, Union

from alembic import op
import sqlalchemy as sa


# revision identifiers, used by Alembic.
revision: str = 'eb2b4ed7a0d7'
down_revision: Union[str, Sequence[str], None] = None
branch_labels: Union[str, Sequence[str], None] = None
depends_on: Union[str, Sequence[str], None] = None


def upgrade() -> None:
    op.create_table('weather_forecast',
        sa.Column('id', sa.Integer(), nullable=False),
        sa.Column('observation_date', sa.Date(), nullable=False),
        sa.Column('observation_time', sa.Time(), nullable=False),
        sa.Column('feels_like_C', sa.String(3), nullable=False),
        sa.Column('temp_C', sa.String(3), nullable=False),
        sa.Column('weather_description_ru', sa.String(), nullable=False),
        sa.Column('visibility', sa.String(2), nullable=False),
        sa.Column('windspeed_kmph', sa.String(3), nullable=False),
        sa.Column('wind_gust', sa.String(3), nullable=False),
        sa.Column('winddir_degree', sa.String(3), nullable=False),
        sa.Column('precip_mm', sa.String(3), nullable=False),
        sa.Column('chance_of_rain', sa.String(3), nullable=False),        
    )

def downgrade() -> None:
    op.drop_table('weather_forecast')