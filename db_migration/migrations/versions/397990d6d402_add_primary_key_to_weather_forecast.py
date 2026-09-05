"""add_primary_key_to_weather_forecast

Revision ID: 397990d6d402
Revises: eb2b4ed7a0d7
Create Date: 2026-09-05 14:34:25.528898

"""
from typing import Sequence, Union

from alembic import op
import sqlalchemy as sa


# revision identifiers, used by Alembic.
revision: str = '397990d6d402'
down_revision: Union[str, Sequence[str], None] = 'eb2b4ed7a0d7'
branch_labels: Union[str, Sequence[str], None] = None
depends_on: Union[str, Sequence[str], None] = None


def upgrade() -> None:
    op.alter_column('weather_forecast', 'id',
                    existing_type=sa.Integer(),
                    nullable=False,
                    autoincrement=True)
    op.create_primary_key('pk_weather_forecast', 'weather_forecast', ['id'])



def downgrade() -> None:
    op.drop_constraint('pk_weather_forecast', 'weather_forecast', type_='primary')
    op.alter_column('weather_forecast', 'id',
                    existing_type=sa.Integer(),
                    nullable=True,
                    autoincrement=False)
